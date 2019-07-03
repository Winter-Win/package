1��iNOC��Ʒ��--��ȫ������
https://www.nowcoder.com/practice/7299c12e6abb437c87ad3e712383ff84?tpId=37&amp;&amp;tqId=21279&amp;rp=1&amp;ru

��Ŀ����
��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����
�����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ���������
���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1+2+4+7+14=28��
��������count(int n),���ڼ���n����(��n)��ȫ���ĸ��������㷶Χ, 0 < n <= 500000
����n������ȫ���ĸ����� �쳣�������-1
/**
 *  ��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����
 *  �����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ���������
 *  ���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5�������1+2+4+7+14=28��
 * 
 *  ��������count(int n),���ڼ���n����(��n)��ȫ���ĸ���
 * @param n  ���㷶Χ, 0 < n <= 500000
 * @return n ������ȫ���ĸ���, �쳣�������-1
 */    
public   static   int  count( int  n)

��������:
����һ������
�������:
�����ȫ���ĸ���
ʾ��1
����
1000
���
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


2��ɾ�������е��ڸ���ֵ val �����нڵ㡣https://leetcode-cn.com/problems/remove-linked-list-elements/
ʾ��:
����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5

C�汾��
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
            //���prev����Ϊ�յĻ���˵����ʱ���ڵ�һ��
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


3������
https://www.nowcoder.com/questionTerminal/e2422543519249f292d8435394ab82fe

���ӣ�https://www.nowcoder.com/questionTerminal/e2422543519249f292d8435394ab82fe
��Դ��ţ����

��������ͨ����һ�����ĸ���λ�ϵ����ּ������õ�������õ�������һλ������ô�������������������������λ�����߰�������λ�����֣���ô�ٰ���Щ���ּ���������˽�����ȥ��ֱ���õ���һλ��Ϊֹ��
���磬����24 ��˵����2 ��4 ��ӵõ�6������6 ��һλ�������6 ��24 ��������
�ٱ���39����3 ��9 �������õ�12������12 ����һλ������˻��ð�1 ��2 �����������õ�3������һ��һλ�������3 ��39 ��������
���ڸ���һ�����������������������

��������:
��������������ݡ�

ÿ���������ݰ���һ��������n��1��n��10E1000����


�������:
��Ӧÿһ�����ݣ��������������������
ʾ��1
����
24
39
���
6
3

#include <iostream>
#include <string>
using namespace std;

int numRoot(int num) {
    int nroot = 0;
    while(num > 0) {
        /*ÿ��ֻ��ȡ��λ����---��λ��+ʮλ��*/
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
        //�Ƚ�ÿһλ������ӵõ��ܺͣ���ֹ���ֹ���
        for (int i = 0; i < origin.length(); i++) {
            sum += origin[i] - '0';
        }
        //���ܺ�������
        cout << numRoot(sum) << endl;
    }
    return 0;
}