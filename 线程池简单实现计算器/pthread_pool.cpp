#include <iostream>
#include <queue>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int cal(int x, int y , int op);//函数放在后面，提前声明一下，声明一个方法，作为实验这个线程池
typedef int (*HandlerTask_t)(int x, int y, int op);//声明一个函数方法，作为输入

class Task
{
private:
    int x;
    int y;
    int op;//0:+,1:-,2:*,3:/
    HandlerTask_t handler;
public:
    Task(int x_ = -1, int y_ = -1, int op_ = -1)
        :x(x_),y(y_),op(op_)
    {
    }

    void Register(HandlerTask_t handler_)
    {
        handler = handler_;
    }

    void Run()
    {
        int ret = handler(x, y, op);
        const char *str = "+-*/";
        cout << "thread is [ " << pthread_self() << " ] handler result : "<<  x <<  str[op] << y << " = " << ret << endl;
    }

    ~Task()
    {
    }
};


class ThreadPool//线程池类
{
private:
    int thread_nums;
    int idle_nums;
    queue<Task> task_queue;
    pthread_mutex_t lock;//创建互斥量
    pthread_cond_t cond;//创建条件变量

public:
    void LockQueue()
    {
        pthread_mutex_lock(&lock);
    }

    void UnLockQueue()
    {
        pthread_mutex_unlock(&lock);
    }

    bool QueueIsEmpty()
    {
        return task_queue.size() == 0 ? true : false;
    }

    void ThreadIdle()
    {
        idle_nums++;
        pthread_cond_wait(&cond, &lock);
        idle_nums--;
    }

    void WakeupThread()
    {
        pthread_cond_signal(&cond);
    }


    void PopTask(Task &t)
    {
        t = task_queue.front();
        task_queue.pop();
    }

public:
    ThreadPool(int num_ =5):thread_nums(num_), idle_nums(0)
    {
        pthread_mutex_init(&lock, NULL);
        pthread_cond_init(&cond, NULL);
    }

    static void *ThreadRotinue(void *arg)
    {
        pthread_detach(pthread_self());
        ThreadPool *tp = (ThreadPool*)arg;

        while(1)
        {
            tp->LockQueue();
            while(tp->QueueIsEmpty())
            {
                tp->ThreadIdle();
            }
            Task t;
            tp->PopTask(t);
            //Task t = task_queue.front();
            //task_queue.pop();
            tp->UnLockQueue();
            t.Run();
        }
    }

    void InitThreadPool()
    {
        pthread_t t;
        for(int i = 0; i < thread_nums; i++)
        {
            pthread_create(&t, NULL, ThreadRotinue, this);
        }
    }

    void PushTask(const Task &t)
    {
        LockQueue();
        task_queue.push(t);
        WakeupThread();
        UnLockQueue();
    }

    ~ThreadPool()
    {
        pthread_mutex_destroy(&lock);
        pthread_cond_destroy(&cond);
    }
};

int cal(int x, int y , int op)//计算器方法实现
{
    int ret = -1;
    switch(op)
    {
        case 0:
            ret = x + y;
            break;
        case 1:
            ret = x - y;
            break;
        case 2:
            ret = x * y;
            break;
        case 3:
            ret = x / y;
            break;
        default:
            cout << "cal error!" << endl;
            break; 
    }
}

int main()
{
    ThreadPool tp;
    tp.InitThreadPool();
    srand((unsigned long)time(NULL));//实现生成随机数种子
    for(;;)
    {
        sleep(1);
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        int op = rand() % 4;
        Task t(x, y, op);
        t.Register(cal);
        tp.PushTask(t);
    }
    return 0;
}
