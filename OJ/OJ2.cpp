1、翻转单词顺序列
https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=11197&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

class Solution {
public:
    string ReverseSentence(string str) {
       int len = str.size();
       int start = 0;
       for(int i = 0; i < len; i ++)
       {
           if(str[i] == ' ')
           {
               reverse(str.begin() + start, str.begin() + i);
               start = i+1;
           }
           if(i == len-1)
           {
               reverse(str.begin() + start, str.end());
           }
       }
       reverse(str.begin(), str.end());
       return str;
    }
};


2、链表中环的入口结点
https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&tPage=3&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        //至少两个节点才能构成环
        if(pHead == NULL || pHead->next == NULL || pHead->next->next == NULL)
            return NULL;
        
        struct ListNode* fast = pHead->next->next;
        struct ListNode* slow = pHead->next;
        
        //先判断有没有环
        while(fast != slow)
        {
            if(fast->next != NULL && fast->next->next != NULL)
            {
                fast = fast->next->next;
                slow=slow->next;
            }
            else
            {
                //没有环,返回
                return NULL;
            }
        }
        
        //循环出来的话就是有环，且此时fast == slow.
        fast = pHead;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};


3、求和
https://www.nowcoder.com/questionTerminal/11cc498832db489786f8a03c3b67d02c

链接：https://www.nowcoder.com/questionTerminal/11cc498832db489786f8a03c3b67d02c
来源：牛客网

输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数,使其和等于 m ,要求将其中所有的可能组合列出来

输入描述:
每个测试输入包含2个整数,n和m

输出描述:
按每个组合的字典序排列输出,每行输出一种组合
示例1
输入
5 5
输出
1 4
2 3
5

#include<iostream>
#include<vector>

using namespace std;

void help(int n, int m, vector<int>& v, int beg) {
    //if (beg>n) return;
    if (m == 0) {
        for (int i = 0; i<v.size(); i++) {
            i == 0 ? cout << v[i] : cout << " " << v[i];
        }
        cout << endl;
    }
    for (int i = beg; i <= n&&i <= m; i++) {
        v.push_back(i);
        help(n, m - i, v, i + 1);
        v.pop_back();
    }
}
int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int>v;
        help(n, m, v, 1);
    }
}


4、进制转换
https://www.nowcoder.com/practice/ac61207721a34b74b06597fe6eb67c52?tpId=85&&tqId=29862&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

题目描述
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
输入描述:
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
输出描述:
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
示例1
输入
7 2
输出
111


#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

string table = "0123456789ABCDEF";

int main()
{
    string s;
    int m, n;
    cin >> m >> n;
    bool flag = false;
    // 如果是负数，则转成正数，并标记一下
    if(m < 0)
    {
        m = 0 - m;
        flag = true;
    }
    // 按进制换算成对应的字符添加到s
    while(m)
    {
        s += table[m % n];
        m /= n;
    }
    if(flag)
        s += "-";
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}



5、24进制转换为10进制

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string table = "0123456789abcdefghijklmn";

size_t Many(char s)
{
	size_t i = 0;
	for (i = 0; i < table.size(); ++i)
	{
		if (s == table[i])
			break;
	}
	return i;
}

int main()
{
	int T;
	while (cin >> T)
	{
		while (T--)
		{
			string M;
			cin >> M;
			reverse(M.begin(), M.end());
			long long ret = 0;
			for (size_t i = 0; i < M.size(); ++i)
			{
				size_t n = Many(M[i]);
				ret += (long long)n * (pow(24, i));
			}
			cout << ret << endl;
		}
	}
	system("pause");
	return 0;
}
