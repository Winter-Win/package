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