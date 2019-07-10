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


6、猴子分桃
https://www.nowcoder.com/questionTerminal/480d2b484e1f43af8ea8434770811b4a

链接：https://www.nowcoder.com/questionTerminal/480d2b484e1f43af8ea8434770811b4a
来源：牛客网

老猴子辛苦了一辈子，给那群小猴子们留下了一笔巨大的财富——一大堆桃子。老猴子决定把这些桃子分给小猴子。
第一个猴子来了，它把桃子分成五堆，五堆一样多，但还多出一个。它把剩下的一个留给老猴子，自己拿走其中的一堆。
第二个猴子来了，它把桃子分成五堆，五堆一样多，但又多出一个。它把多出的一个留给老猴子，自己拿走其中的一堆。
后来的小猴子都如此照办。最后剩下的桃子全部留给老猴子。
这里有n只小猴子，请你写个程序计算一下在开始时至少有多少个桃子，以及最后老猴子最少能得到几个桃子。

输入描述:
输入包括多组测试数据。
每组测试数据包括一个整数n(1≤n≤20)。
输入以0结束，该行不做处理。


输出描述:
每组测试数据对应一行输出。
包括两个整数a，b。
分别代表开始时最小需要的桃子数，和结束后老猴子最少能得到的桃子数。
示例1
输入
5
1
0
输出
3121 1025
1 1

// write your code here cpp
#include <iostream>
#include <string>
#include <math.h>
int main()
{
    int n;
    while(std::cin >> n) {
        if (n == 0) break;
        long total = pow(5, n) - 4;
        long left = pow(4, n) + n - 4;
        std::cout << total << " " << left << std::endl;
    }
    return 0;
}



7、因子个数
https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d

链接：https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
来源：牛客网

一个正整数可以分解成一个或多个数组的积。例如36=2*2*3*3，即包含2和3两个因子。NowCoder最近在研究因子个数的分布规律，现在给出一系列正整数，他希望你开发一个程序输出每个正整数的因子个数。

输入描述:
输入包括多组数据。
每组数据仅有一个整数n (2≤n≤100000)。


输出描述:
对应每个整数，输出其因子个数，每个结果占一行。
示例1
输入
30
26
20
输出
3
2
2

#include <iostream>
#include<math.h>
using namespace std;
int main()
{
    int n, k, i;
    while(cin >> n)
    {
        k = 0;
        for(i = 2; i <= sqrt(n); i++)
        {
            if ((n % i) == 0)
            {
                while((n % i) == 0)
                {
                    n/= i;
                }
                k++;
            }
        }
        if(n != 1)
            k++;
        cout << k << endl;
    }
    return 0;
}


8、最难的问题
https://www.nowcoder.com/questionTerminal/9f6b8f6ec26d44cfb8fc8c664b0edb6b

链接：https://www.nowcoder.com/questionTerminal/9f6b8f6ec26d44cfb8fc8c664b0edb6b
来源：牛客网

NowCoder生活在充满危险和阴谋的年代。为了生存，他首次发明了密码，用于军队的消息传递。假设你是军团中的一名军官，需要把发送来的消息破译出来、并提
供给你的将军。
消息加密的办法是：对消息原文中的每个字母，分别用该字母之后的第5个字母替换（例如：消息原文中的每个字母A 都分别替换成字母F），其他字符不 变，并且消息原文的所有字母都是大写的。密码中的字母与原文中的字母对应关系如下。
密码字母：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
原文字母：V W X Y Z A B C D E F G H I J K L M N O P Q R S T U

输入描述:
输入包括多组数据，每组数据一行，为收到的密文。
密文仅有空格和大写字母组成。


输出描述:
对应每一组数据，输出解密后的明文。
示例1
输入
HELLO WORLD
SNHJ
输出
CZGGJ RJMGY
NICE

#include <stdio.h>
int main() {
    char c;
    while ((c = getchar()) != EOF){
        if ('A' <= c && 'Z' >= c) {
            c = (c > 'E') ? (c - 5) : (c + 21);
        }
        putchar(c);
    }
    return 0;
}


9、斐波那契凤尾
https://www.nowcoder.com/questionTerminal/c0a4b917a15f40a49ca10532ab9019fb

链接：https://www.nowcoder.com/questionTerminal/c0a4b917a15f40a49ca10532ab9019fb
来源：牛客网

NowCoder号称自己已经记住了1-100000之间所有的斐波那契数。
为了考验他，我们随便出一个数n，让他说出第n个斐波那契数。当然，斐波那契数会很大。因此，如果第n个斐波那契数不到6位，则说出该数；否则只说出最后6位。

输入描述:
输入有多组数据。
每组数据一行，包含一个整数n (1≤n≤100000)。


输出描述:
对应每一组输入，输出第n个斐波那契数的最后6位。
示例1
输入
1
2
3
4
100000
输出
1
2
3
5
537501

#include <iostream>
using namespace std;

int main()
{
    int Fib[100001] = {0};
    Fib[0] = 1;
    Fib[1] = 1;
    for(int i = 2; i < 100001; ++i)
    {
        // 计算所有的斐波那契数
        Fib[i] = Fib[i-1] + Fib[i-2];
        //  提前处理只保留后六位
        Fib[i] %= 1000000;
    }
    //  记录分界值
    int ret = 0;
    for(ret = 2; ret < 100001; ++ret)
    {
        if(Fib[ret] >= 100000)
            break;
    }
    //  循环输入
    int n;
    while(cin >> n)
    {
        //  原因是在开始报尾数六位的时候，很有可能因为前面的取模运算
        //  数字不够六位，所以拆分后进行前面补0
        if(n < ret)
            printf("%d\n", Fib[n]);
        else
            printf("%06d\n", Fib[n]);
    }
    
    return 0;
}