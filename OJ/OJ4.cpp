1、iNOC产品部--完全数计算
https://www.nowcoder.com/practice/7299c12e6abb437c87ad3e712383ff84?tpId=37&amp;&amp;tqId=21279&amp;rp=1&amp;ru

题目描述
完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。
给定函数count(int n),用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000
返回n以内完全数的个数。 异常情况返回-1
/**
 *  完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
 *  它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
 *  例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加1+2+4+7+14=28。
 * 
 *  给定函数count(int n),用于计算n以内(含n)完全数的个数
 * @param n  计算范围, 0 < n <= 500000
 * @return n 以内完全数的个数, 异常情况返回-1
 */    
public   static   int  count( int  n)

输入描述:
输入一个数字
输出描述:
输出完全数的个数
示例1
输入
1000
输出
3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Divisor(int n, vector<int>& v)
{
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            v.push_back(i);
    }
}

bool IsPerfectNum(int n)
{
    vector<int> v;
    Divisor(n, v);
    int sum = 0;
    for(size_t i = 0; i < v.size(); ++i)
    {
        sum += v[i];
    }
    if(sum == n)
        return true;
    return false;
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(n > 0 && n <= 500000)
        {
            int count = 0;
            for(int i = 1; i <= n; i++)
            {
                if(IsPerfectNum(i))
                    count++;
            }
            cout << count << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}


2、删除链表中等于给定值 val 的所有节点。
https://leetcode-cn.com/problems/remove-linked-list-elements/
示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

C版本：
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL)
    {
         return NULL;
    }
    
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    
    while(cur)
    {
        struct ListNode* next = cur->next;
        if(cur->val == val)
        {
            //如果prev还是为空的话，说明此时是在第一个
            if(prev == NULL)
            {
                head = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }
            free(cur);
            cur = next;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}


3、数根
https://www.nowcoder.com/questionTerminal/e2422543519249f292d8435394ab82fe

链接：https://www.nowcoder.com/questionTerminal/e2422543519249f292d8435394ab82fe
来源：牛客网

数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根；如果结果是两位数或者包括更多位的数字，那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。
比如，对于24 来说，把2 和4 相加得到6，由于6 是一位数，因此6 是24 的数根。
再比如39，把3 和9 加起来得到12，由于12 不是一位数，因此还得把1 和2 加起来，最后得到3，这是一个一位数，因此3 是39 的数根。
现在给你一个正整数，输出它的数根。

输入描述:
输入包含多组数据。

每组数据数据包含一个正整数n（1≤n≤10E1000）。


输出描述:
对应每一组数据，输出该正整数的数根。
示例1
输入
24
39
输出
6
3

#include <iostream>
#include <string>
using namespace std;

int numRoot(int num) {
    int nroot = 0;
    while(num > 0) {
        /*每次只获取个位数字---个位数+十位数*/
        nroot += num % 10;
        num /= 10;
    }
    while (nroot > 9) {
        nroot = numRoot(nroot);
    }
    return nroot;
}
int main()
{
    string origin;
    while(cin >> origin) {
        int sum = 0;
        //先将每一位进行相加得到总和，防止数字过大
        for (int i = 0; i < origin.length(); i++) {
            sum += origin[i] - '0';
        }
        //对总和求树根
        cout << numRoot(sum) << endl;
    }
    return 0;
}

4、星际密码
https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
链接：https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
来源：牛客网

星际战争开展了100年之后，NowCoder终于破译了外星人的密码！他们的密码是一串整数，通过一张表里的信息映射成最终4位密码。表的规则是：n对应的值是矩阵X的n次方的左上角，如果这个数不足4位则用0填充，如果大于4位的则只输出最后4位。
|1 1|^n => |Xn ..|
|1 0|      |.. ..|
例如n=2时，
|1 1|^2 => |1 1| * |1 1| => |2 1|
|1 0|      |1 0|   |1 0|    |1 1|
即2对应的数是“0002”。

输入描述:
输入有多组数据。
每组数据两行：第一行包含一个整数n (1≤n≤100)；第二行包含n个正整数Xi (1≤Xi≤10000)


输出描述:
对应每一组输入，输出一行相应的密码。
示例1
输入
6
18 15 21 13 25 27
5
1 10 100 1000 10000
输出
418109877711037713937811
00010089410135017501

#include <iostream>
#include <vector>
using namespace std;

vector<int> a = {1,1};
void data_init()
{
    int i;
    for(i=2;i<10005;i++){
        a.push_back((a[i-1]+a[i-2]) % 10000);
    }
}
int main()
{
    int n,t;
    data_init();
    while(std::cin >> n){
        while(n--){
            cin >> t;
            printf("%04d",a[t]);
        }
        printf("\n");
    }
    return 0;
}



4、检查不重复数字
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//找出这两个数字，编程实现。
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void Find_num(int *arr, int sz, int *px, int *py)
{
	//1.先将全部异或
	int num = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		num ^= arr[i];
	}
	//2.找出异或为1的位置
	int pos = 0;
	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1);
		{
			pos = i;
			break;
		}
	}
	//3.按照分组将数字找出
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			*px ^= arr[i];
		}
		else
			*py ^= arr[i];
	}
}



int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int n1 = 0;
	int n2 = 0;
	Find_num(arr, sz, &n1, &n2);
	printf("%d %d\n", n1, n2);
	system("pause");
	return 0;
}


5、有假币
https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c

链接：https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
来源：牛客网

居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。nowcoder这就去买猪肉，结果找来的零钱中有假币！！！可惜nowcoder 一不小心把它混进了一堆真币里面去了。只知道假币的重量比真币的质量要轻，给你一个天平（天平两端能容纳无限个硬币），请用最快的时间把那个可恶的假币找出来。

输入描述:
1≤n≤2^30,输入0结束程序。


输出描述:
最多要称几次一定能把那个假币找出来？
示例1
输入
3
12
0
输出
1
3

// write your code here cpp
#include <stdio.h>

//  首先要最快时间找出来，本来想用二分查找，
//  但是发现分三堆是最快的，而且是合理的，
//  用两堆称，就可判断，我们只需要找出来即可

int main()
{
    int n = 0;
    while(scanf("%d", &n) != EOF)
    {
        int count = 0;
        if(n == 0)
            break;
        while(n > 1)
        {
            if(n % 3 != 0)
            {
                n = n / 3 + 1;
            }
            else
            {
                n /= 3;
            }
            count++;
        }
        printf("%d\n", count);
    }
    return 0;
}