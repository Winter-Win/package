1����ת����˳����
https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=11197&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼�����磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��

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


2�������л�����ڽ��
https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&tPage=3&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��

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
        //���������ڵ���ܹ��ɻ�
        if(pHead == NULL || pHead->next == NULL || pHead->next->next == NULL)
            return NULL;
        
        struct ListNode* fast = pHead->next->next;
        struct ListNode* slow = pHead->next;
        
        //���ж���û�л�
        while(fast != slow)
        {
            if(fast->next != NULL && fast->next->next != NULL)
            {
                fast = fast->next->next;
                slow=slow->next;
            }
            else
            {
                //û�л�,����
                return NULL;
            }
        }
        
        //ѭ�������Ļ������л����Ҵ�ʱfast == slow.
        fast = pHead;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};


3�����
https://www.nowcoder.com/questionTerminal/11cc498832db489786f8a03c3b67d02c

���ӣ�https://www.nowcoder.com/questionTerminal/11cc498832db489786f8a03c3b67d02c
��Դ��ţ����

������������ n �� m��������1��2��3.......n ������ȡ������,ʹ��͵��� m ,Ҫ���������еĿ�������г���

��������:
ÿ�������������2������,n��m

�������:
��ÿ����ϵ��ֵ����������,ÿ�����һ�����
ʾ��1
����
5 5
���
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


4������ת��
https://www.nowcoder.com/practice/ac61207721a34b74b06597fe6eb67c52?tpId=85&&tqId=29862&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

��Ŀ����
����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������
��������:
����Ϊһ�У�M(32λ����)��N(2 �� N �� 16)���Կո������
�������:
Ϊÿ������ʵ�����ת���������ÿ�����ռһ�С����N����9�����Ӧ�����ֹ���ο�16���ƣ����磬10��A��ʾ���ȵȣ�
ʾ��1
����
7 2
���
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
    // ����Ǹ�������ת�������������һ��
    if(m < 0)
    {
        m = 0 - m;
        flag = true;
    }
    // �����ƻ���ɶ�Ӧ���ַ���ӵ�s
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



5��24����ת��Ϊ10����

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


6���������򷽷�
https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ffe432?tpId=85&&tqId=29844&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

��Ŀ����
������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 1.�����ַ������ֵ����������磺
"car" < "carriage" < "cats" < "doggies < "koala"
2.�����ַ����ĳ����������磺
"car" < "cats" < "koala" < "doggies" < "carriage"
������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��
��������:
�����һ��Ϊ�ַ�������n(n �� 100)
��������n��,ÿ��һ���ַ���,�ַ������Ⱦ�С��100������Сд��ĸ���
�������:
�����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically",

������ݳ������ж������ֵ����������"lengths",

������ַ�ʽ���������"both"���������"none"
ʾ��1
����
3
a
aa
bbb
���
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