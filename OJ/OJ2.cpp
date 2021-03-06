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


6、两种排序方法
https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ffe432?tpId=85&&tqId=29844&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

题目描述
考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
输入描述:
输入第一行为字符串个数n(n ≤ 100)
接下来的n行,每行一个字符串,字符串长度均小于100，均由小写字母组成
输出描述:
如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",

如果根据长度排列而不是字典序排列输出"lengths",

如果两种方式都符合输出"both"，否则输出"none"
示例1
输入
3
a
aa
bbb
输出
both


#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsDictSort(const vector<string>& vs)
{
    for(size_t i = 1; i < vs.size(); ++i)
    {
        if(vs[i] < vs[i-1])
            return false;
    }
    return true;
}

bool IsLengthsSort(const vector<string>& vs)
{
    for(size_t i = 1; i < vs.size(); ++i)
    {
        if(vs[i].size() < vs[i-1].size())
            return false;
    }
    return true;
}

int main()
{
    int n;
    while(cin >> n)
    {
        vector<string> vs(n);
        for(int i = 0; i < n; ++i)
            cin >> vs[i];
        
        if(IsDictSort(vs) && IsLengthsSort(vs))
            cout << "both" << endl;
        else if(IsDictSort(vs))
            cout << "lexicographically" << endl;
        else if(IsLengthsSort(vs))
            cout << "lengths" << endl;
        else
            cout << "none" << endl;
    }
    return 0;
}

7、求最小公倍数
https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3?tpId=37&&tqId=21331&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

题目描述
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。

输入描述:
输入两个正整数A和B。

输出描述:
输出A和B的最小公倍数。

示例1
输入
5 
7
输出
35

#include<iostream>

using namespace std;

//先求最大公约数
//辗转相除法
//非递归
int Gcd1(int a, int b)
{
    while(a % b)
    {
        int r = a;
        a = b;
        b = r % b;
    }
    return b;
}

//递归
int Gcd2(int a, int b)
{
    if (b == 0)
        return a;
    return Gcd2(b, a % b);
}

//更相减损术
//建议用辗转相除法，时间复杂度比更相减损术要低
//递归
int Gcd3(int a, int b)
{
    if(a > b)
        return Gcd4(a - b, b);
    else if(a < b)
        return Gcd4(a, b - a);
    else
        return a;
}

int main()
{
    int A, B;
    while(cin >> A >> B)
    {
        cout << A * B / Gcd1(A, B) << endl;
    }
     return 0;
}


8、查找组成一个偶数最接近的两个素数
https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId=37&&tqId=21283&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对
输入描述:
输入一个偶数

输出描述:
输出两个素数

示例1
输入
20
输出
7
13

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int num)
{
    int tmp = sqrt(num);
    //只遍历到开方处，不能被开方左边的数整除，则一定不能被开方右边的数整除
    for (int i = 2; i <= tmp; i++)
    {
        if (num %i == 0)
            return false;
    }
    return true;
}

int main()
{
    int num;
    int half;
    int i;
    while (cin >> num)
    {
        half = num / 2;
        //从中间向两边找
        for (i = half; i > 0; i--)
        {
            if(isPrime(i) && isPrime(num - i))
                break;
        }
        cout << i << endl;
        cout << num - i << endl;
    }
    return 0;
}


9、井字棋
https://www.nowcoder.com/practice/e1bb714eb9924188a0d5a6df2216a3d1?tpId=8&&tqId=11055&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking

题目描述
对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。

给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。

测试样例：
[[1,0,1],[1,-1,-1],[1,-1,0]]
返回：true

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        int row = board.size();
        //检查每一行的和是是否等于row
        int i,j,sum;
        for(i=0;i<row;i++)
        {
            sum = 0;
            for(j=0;j<row;j++)
            {
                sum += board[i][j];
            }
            if(sum==row)
                return true;
        }
        //检查每一列的和是是否等于row
        for(i=0;i<row;i++)
        {
            sum = 0;
            for(j=0;j<row;j++)
            {
                sum += board[j][i];
            }
            if(sum==row)
            return true;
        }
        //检查主对角线的和是是否等于row
        sum = 0;
        for(i=0;i<row;i++)
        {
            sum += board[i][i];
        }
        if(sum==row)
            return true;
        //检查副对角线的和是是否等于row
        sum = 0;
        for(i=0;i<row;i++)
        {
            sum += board[i][row-i-1];
        }
        if(sum==row)
            return true;
        return false;
    }
};


10、A+B和C
https://www.nowcoder.com/pat/6/problem/4077

题目描述
给定区间[-2的31次方, 2的31次方]内的3个整数A、B和C，请判断A+B是否大于C。

输入描述:
输入第1行给出正整数T(<=10)，是测试用例的个数。随后给出T组测试用例，每组占一行，顺序给出A、B和C。整数间以空格分隔。

输出描述:
对每组测试用例，在一行中输出“Case #X: true”如果A+B>C，否则输出“Case #X: false”，其中X是测试用例的编号（从1开始）。

输入例子:
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647

输出例子:
Case #1: false
Case #2: true
Case #3: true
Case #4: false

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<vector<int> > vv(T);
    for(int i = 0; i < T; ++i)
    {
        vv[i].resize(3);
        cin >> vv[i][0] >> vv[i][1] >> vv[i][2];
    }
    for(int i = 0; i < T; ++i)
    {
        if(vv[i][0] > vv[i][2] - vv[i][1])
            cout << "Case #" << i+1 << ": true" << endl;
        else
            cout << "Case #" << i+1 << ": false" << endl;
    }
    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int i = 1;
    while(T--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        if(A > C - B)
            cout << "Case #" << i << ": true" << endl;
        else
            cout << "Case #" << i << ": false" << endl;
        i++;
    }
    return 0;
}