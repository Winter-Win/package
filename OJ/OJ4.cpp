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


2��ɾ�������е��ڸ���ֵ val �����нڵ㡣
https://leetcode-cn.com/problems/remove-linked-list-elements/
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

4���Ǽ�����
https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
���ӣ�https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
��Դ��ţ����

�Ǽ�ս����չ��100��֮��NowCoder���������������˵����룡���ǵ�������һ��������ͨ��һ�ű������Ϣӳ�������4λ���롣��Ĺ����ǣ�n��Ӧ��ֵ�Ǿ���X��n�η������Ͻǣ�������������4λ����0��䣬�������4λ����ֻ������4λ��
|1 1|^n => |Xn ..|
|1 0|      |.. ..|
����n=2ʱ��
|1 1|^2 => |1 1| * |1 1| => |2 1|
|1 0|      |1 0|   |1 0|    |1 1|
��2��Ӧ�����ǡ�0002����

��������:
�����ж������ݡ�
ÿ���������У���һ�а���һ������n (1��n��100)���ڶ��а���n��������Xi (1��Xi��10000)


�������:
��Ӧÿһ�����룬���һ����Ӧ�����롣
ʾ��1
����
6
18 15 21 13 25 27
5
1 10 100 1000 10000
���
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



4����鲻�ظ�����
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//�ҳ����������֣����ʵ�֡�
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void Find_num(int *arr, int sz, int *px, int *py)
{
	//1.�Ƚ�ȫ�����
	int num = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		num ^= arr[i];
	}
	//2.�ҳ����Ϊ1��λ��
	int pos = 0;
	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1);
		{
			pos = i;
			break;
		}
	}
	//3.���շ��齫�����ҳ�
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


5���мٱ�
https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c

���ӣ�https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
��Դ��ţ����

��Ȼ�мٱң� �����������ˣ�����ũ��Ĺ���ȴ�����ǰ���ûǮ��ô�����Ⱑ��nowcoder���ȥ�����⣬�����������Ǯ���мٱң�������ϧnowcoder һ��С�İ��������һ���������ȥ�ˡ�ֻ֪���ٱҵ���������ҵ�����Ҫ�ᣬ����һ����ƽ����ƽ�������������޸�Ӳ�ң�����������ʱ����Ǹ��ɶ�ļٱ��ҳ�����

��������:
1��n��2^30,����0��������


�������:
���Ҫ�Ƽ���һ���ܰ��Ǹ��ٱ��ҳ�����
ʾ��1
����
3
12
0
���
1
3

// write your code here cpp
#include <stdio.h>

//  ����Ҫ���ʱ���ҳ������������ö��ֲ��ң�
//  ���Ƿ��ַ����������ģ������Ǻ���ģ�
//  �����ѳƣ��Ϳ��жϣ�����ֻ��Ҫ�ҳ�������

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


6�����ӷ���
https://www.nowcoder.com/questionTerminal/480d2b484e1f43af8ea8434770811b4a

���ӣ�https://www.nowcoder.com/questionTerminal/480d2b484e1f43af8ea8434770811b4a
��Դ��ţ����

�Ϻ���������һ���ӣ�����ȺС������������һ�ʾ޴�ĲƸ�����һ������ӡ��Ϻ��Ӿ�������Щ���ӷָ�С���ӡ�
��һ���������ˣ��������ӷֳ���ѣ����һ���࣬�������һ��������ʣ�µ�һ�������Ϻ��ӣ��Լ��������е�һ�ѡ�
�ڶ����������ˣ��������ӷֳ���ѣ����һ���࣬���ֶ��һ�������Ѷ����һ�������Ϻ��ӣ��Լ��������е�һ�ѡ�
������С���Ӷ�����հ졣���ʣ�µ�����ȫ�������Ϻ��ӡ�
������nֻС���ӣ�����д���������һ���ڿ�ʼʱ�����ж��ٸ����ӣ��Լ�����Ϻ��������ܵõ��������ӡ�

��������:
�����������������ݡ�
ÿ��������ݰ���һ������n(1��n��20)��
������0���������в�������


�������:
ÿ��������ݶ�Ӧһ�������
������������a��b��
�ֱ����ʼʱ��С��Ҫ�����������ͽ������Ϻ��������ܵõ�����������
ʾ��1
����
5
1
0
���
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



7�����Ӹ���
https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d

���ӣ�https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
��Դ��ţ����

һ�����������Էֽ��һ����������Ļ�������36=2*2*3*3��������2��3�������ӡ�NowCoder������о����Ӹ����ķֲ����ɣ����ڸ���һϵ������������ϣ���㿪��һ���������ÿ�������������Ӹ�����

��������:
��������������ݡ�
ÿ�����ݽ���һ������n (2��n��100000)��


�������:
��Ӧÿ����������������Ӹ�����ÿ�����ռһ�С�
ʾ��1
����
30
26
20
���
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


8�����ѵ�����
https://www.nowcoder.com/questionTerminal/9f6b8f6ec26d44cfb8fc8c664b0edb6b

���ӣ�https://www.nowcoder.com/questionTerminal/9f6b8f6ec26d44cfb8fc8c664b0edb6b
��Դ��ţ����

NowCoder�����ڳ���Σ�պ���ı�������Ϊ�����棬���״η��������룬���ھ��ӵ���Ϣ���ݡ��������Ǿ����е�һ�����٣���Ҫ�ѷ���������Ϣ�������������
������Ľ�����
��Ϣ���ܵİ취�ǣ�����Ϣԭ���е�ÿ����ĸ���ֱ��ø���ĸ֮��ĵ�5����ĸ�滻�����磺��Ϣԭ���е�ÿ����ĸA ���ֱ��滻����ĸF���������ַ��� �䣬������Ϣԭ�ĵ�������ĸ���Ǵ�д�ġ������е���ĸ��ԭ���е���ĸ��Ӧ��ϵ���¡�
������ĸ��A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
ԭ����ĸ��V W X Y Z A B C D E F G H I J K L M N O P Q R S T U

��������:
��������������ݣ�ÿ������һ�У�Ϊ�յ������ġ�
���Ľ��пո�ʹ�д��ĸ��ɡ�


�������:
��Ӧÿһ�����ݣ�������ܺ�����ġ�
ʾ��1
����
HELLO WORLD
SNHJ
���
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


9��쳲�������β
https://www.nowcoder.com/questionTerminal/c0a4b917a15f40a49ca10532ab9019fb

���ӣ�https://www.nowcoder.com/questionTerminal/c0a4b917a15f40a49ca10532ab9019fb
��Դ��ţ����

NowCoder�ų��Լ��Ѿ���ס��1-100000֮�����е�쳲���������
Ϊ�˿���������������һ����n������˵����n��쳲�����������Ȼ��쳲���������ܴ���ˣ������n��쳲�����������6λ����˵������������ֻ˵�����6λ��

��������:
�����ж������ݡ�
ÿ������һ�У�����һ������n (1��n��100000)��


�������:
��Ӧÿһ�����룬�����n��쳲������������6λ��
ʾ��1
����
1
2
3
4
100000
���
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
        // �������е�쳲�������
        Fib[i] = Fib[i-1] + Fib[i-2];
        //  ��ǰ����ֻ��������λ
        Fib[i] %= 1000000;
    }
    //  ��¼�ֽ�ֵ
    int ret = 0;
    for(ret = 2; ret < 100001; ++ret)
    {
        if(Fib[ret] >= 100000)
            break;
    }
    //  ѭ������
    int n;
    while(cin >> n)
    {
        //  ԭ�����ڿ�ʼ��β����λ��ʱ�򣬺��п�����Ϊǰ���ȡģ����
        //  ���ֲ�����λ�����Բ�ֺ����ǰ�油0
        if(n < ret)
            printf("%d\n", Fib[n]);
        else
            printf("%06d\n", Fib[n]);
    }
    
    return 0;
}