1������
https://www.nowcoder.com/practice/365d5722fff640a0b6684391153e58d8?tpId=49&&tqId=29337&rp=1&ru=/

��Ŀ����
�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��A��������Ҫ���ţ�������Ҫȥ������ѡ���ס����ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��ֻ�ֱܷ�������֡������������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס����ڵ������ǣ�������Ҫ�ö���ֻ����(���ּ�����)�����ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�

������ɫ����n(1��n��13),ͬʱ������������Ϊn������left,right,�ֱ����ÿ����ɫ���������׵����������ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�������

����������
4,[0,7,1,6],[1,5,0,6]
���أ�10(���ͣ�������������ȡ2ֻ����������ȡ8ֻ)

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        // ����Ŀ��������
        // �������˼������ȡ�����������ٿ����γ�һ����ϵ���������������
        // ��Ŀ�������������Ӧλ�ñ�ʾͬһ����ɫ���������������� 
        // ������˼·����
        // ���ڷ�0��������a1,a2...an��Ҫ������ȡֵ����ÿһ������ n = sum(a1...an) - a1 +1
        // ��Ҳ����������ȥ��Сֵ֮���һ�� ���Զ���������������ɫ�������������У�
        // ��Ҫ����ÿһ����ɫ������С����leftsum = ��������� - �����Сֵ + 1��
        // rightsum =�ұ������� - �ұߵ���Сֵ + 1����������0���ڵģ�����Ҫ���ۼӣ���֤����ÿһ����ɫ��
        
        int left_sum = 0, left_min = INT_MAX;
        int right_sum = 0, right_min = INT_MAX;
        int sum = 0;
        //����ÿ����ɫ��������������
        for(int i = 0; i < n; ++i)
        {
            // ���ڴ���Ϊ0����ɫ���ף��ۼ�
            if(left[i] * right[i] == 0)
                sum += left[i] + right[i];
            // ���������ֶ�����ɫ�ģ�ִ���ۼ� - ��Сֵ + 1
            // �ҵ���Сֵ������
            else
            {
                left_sum += left[i];
                right_sum += right[i];
                
                if(left_min > left[i])
                    left_min = left[i];
                if(right_min >  right[i])
                    right_min = right[i];
                
                // left_min = min(left_min, left[i]);
                // right_min = min(right_min, right[i]);
            }
        }
        // �����׵Ľ�� + ����0�� + 1
        return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
    }
};

2���˿��ƴ�С
https://www.nowcoder.com/practice/0a92c75f5d6b4db28fcfa3e65e5c9b3f?tpId=49&&tqId=29277&rp=1&ru=/

��Ŀ����
�˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š������С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ������:) 
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER 
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո��磺4 4 4 4-joker JOKER
��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR

��������
��1������ÿ���ƿ����Ǹ��ӣ����ӣ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣���������������������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ�
��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӣ����ӣ������Ƚ������С��˳�ӱȽ���С�ƴ�С��ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
��4������������Ʋ��������ȵ������

����ʾ��
��1������ը���Ͷ���֮�⣬��������ͬ���ͱȽϡ�
��2�������Ѿ���֤�Ϸ��ԣ����ü�������Ƿ��ǺϷ����ơ�
��3�������˳���Ѿ�������С����������˲�����������.
��������:
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո���4 4 4 4-joker JOKER��
�������:
����������нϴ�����֣��������ӷ����˿���˳�򲻱䣬���Կո��������������ڱȽϹ�ϵ�����ERROR��
ʾ��1
����
4 4 4 4-joker JOKER
���
joker JOKER


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string Poker;
    while(getline(cin, Poker))
    {
        //��ը���ֱ�����
        if (Poker.find("joker JOKER") != -1)
            cout << "joker JOKER" << endl;
        else
        {
            int dash = Poker.find('-');
            // ����
            string P1 = Poker.substr(0, dash);
            string P2 = Poker.substr(dash + 1);
            
            //  ��¼�ո�Ĵ���
            int num1 = count(P1.begin(), P1.end(), ' ');
            int num2 = count(P2.begin(), P2.end(), ' ');
            
            //  �õ���һ���ƣ����ں���ıȽ�
            string first1 = P1.substr(0, P1.find(' '));
            string first2 = P2.substr(0, P2.find(' '));
            string str = "345678910JQKA2jokerJOKER";
            if (num1 == num2)
            {
                //ֻҪ������ȣ����һ���ƴ�ļ�Ϊ��
                if (str.find(first1) >str.find(first2))
                    cout << P1 << endl;
                else
                    cout << P2 << endl;
             }
             else
             {
                //��������ͬ��˵�����Ͳ�ͬ,ֻ��ը�����Ժ������ƱȽ�
                //�������Ͷ��Ǵ����
                if (num1 == 3)
                    cout << P1 << endl;
                else if (num2 == 3)
                    cout << P2 << endl;
                else
                    cout << "ERROR" << endl;
            }
        }
    }
    return 0;
}


3��iNOC��Ʒ��-������ǵı���
https://www.nowcoder.com/practice/8ef655edf42d4e08b44be4d777edbf43?tpId=37&amp;&amp;tqId=21276&amp;rp=1&amp;ru

��Ŀ����
            1

         1  1  1

      1  2  3  2  1

   1  3  6  7  6  3  1

1  4  10 16 19  16 10  4  1

���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ��������0����

���n�е�һ��ż�����ֵ�λ�á����û��ż���������-1����������3,�����2������4�����3��

 

����n(n <= 1000000000)
��������:
����һ��int����

�������:
������ص�intֵ

ʾ��1
����
4
���
3


#include <iostream>
#include <vector>
using namespace std;

//             1
//          1  1  1
//       1  2  3  2  1
//    1  3  6  7  6  3  1
// 1  4  10 16 19 16 10 4  1

//  ������Ŀ��˼�����Է��ֵ�n����2n -1��Ԫ�أ���i,jԪ�ص�����һ�е�j -2,j -1,j����Ԫ��֮��
//  ÿһ�еĵ�һ�к����һ�ж�Ϊ1������ǵڶ��У���ֻ������Ԫ��֮�͡�

int main()
{
    int n;
    while(cin >> n)
    {
        int m = (n << 1) - 1;
        //  ��������ά���鿪�ٳ���ȫ���ȳ�ʼ��Ϊ0
        vector<vector<int> > vv(n, vector<int>(m, 0));
        //  ����һ������Ϊ1
        vv[0][0] = 1;
        for(int i = 1; i < n; ++i)
        {
            //  ��ÿ�еĶ�Ӧ����β������Ϊ1
            vv[i][0] = vv[i][2 * i] = 1;
            for(int j = 1; j < 2 * i; ++j)
            {
                //  ���ֻ�ǵڶ��У�ֻ��Ҫ����Ԫ��֮��
                if(j == 1)
                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
                else
                    //  ������һ�е�j - 2, j - 1, j����Ԫ��֮��
                    vv[i][j] = vv[i - 1][j - 2] + vv[i - 1][j - 1] + vv[i - 1][j];
            }
        }
        
        int k;
        for(k = 0; k < m; ++k)
        {
            if(vv[n - 1][k] % 2 == 0 && vv[n - 1][k] != 0)
            {
                cout << k + 1 << endl;
                break;
            }
        }
        //  �������ˣ�˵��û�ҵ�
        if(k == m)
            cout << -1 << endl;
    }
    return 0;
}


4�������������
https://www.nowcoder.com/practice/5821836e0ec140c1aa29510fd05f45fc?tpId=37&&tqId=21301&rp=1&ru=/

��Ŀ����
�����һ���㷨������������������ļӷ���

�ӿ�˵��
 /*
 �����һ���㷨������������������ļӷ���
 ���������
 String addend������
 String augend��������
 ����ֵ���ӷ����
 */
 public String AddLongInteger(String addend, String augend)
 {
     /*������ʵ�ֹ���*/
	return null;     
 }

��������:
���������ַ�������

�������:
�����Ӻ�Ľ����string��

ʾ��1
����
99999999999999999999999999999999999999999999999999
1
���
100000000000000000000000000000000000000000000000000

//  �ӷ����㣬ÿһλ��ֵ���ڵ�ǰ��Ӧλ������֮��+��λ�������Ǽӷ������Ե�ǰλ�ĺ������19��9 + 9 + ��λ1)��
//  ���Բ����Ľ�λ���Ϊ1����
//  ��һ���������Ӧλ�ĺͣ���Ӧλ��� + ��һλ�Ľ�λ
//  �ڶ��������µ�ǰλ��ֵ�� �� % 10 ����ֵת���ַ����� -'0'�������ַ������
//  �����������½�λ�� �� / 10�� Ȼ�������һλ��ֵ
//  ���һ�������������֮�󣬽�λΪ1��˵�����λ�����˽�λ��������Ҫ�ټ�һλ���������Ľ�����������֮
//  ����Ҫ���ã��õ����ս����

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
string addStrings(string num1, string num2)
{
    //�ɵ�λ���λ���
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    string result = "";
    //��ǰλ����ӽ��
    int carry = 0;
    while (i >= 0 || j >= 0)
    {
        if (i >= 0)
        {
            carry += num1[i] - '0';
        }
        if (j >= 0) 
        {
            carry += num2[j] - '0';
        }
        //��ǰΪ�����ֵ������10
        result += (char)(carry % 10 + '0');
        //�������10,���Ͻ�һλ
        carry /= 10;
        i--;
        j--;
    }
    //�����֮��������н�λ�����ټ�1
    if (carry == 1)
    { 
        result += '1';
    }
    //��������
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string s1, s2;
    while(cin>>s1>>s2)
    {
    cout<<addStrings(s1, s2)<<endl;
    }
    return 0;
}


//////////////////////////////////////////////////////////////////////////

1������һ��ӵ�����Ԫ�ص����飬ÿ��Ԫ�ض���һ��ָ�����������ֵΪint������Ϊ����int�ĺ���ָ��������ָ��
int *(*p[5][5])(int, int);

//  ���ڶ���༶ָ�룬���� * �ü��� p �������Լ���죬��˵��һ��*���Ե���һ��p 

2�����еĽ����ò��������������ں���ָ�룬����Ϊ��Ч����û��*,����Ӱ�죬����ָ��ֻ��һ�������ϵ�ָ�룬����ʵ�ʵ�ָ��
int ��*pfunc��(int, int) = add;
//  add��ʱû�пռ䣬��ֵ��ȥ��ֻ��һ���ٵĵ�ַ
//  addǰ��Ӳ���&���ţ�����Ϊ��Ч

3��
struct list{
  int data;
  struct list * next;
};
//  * ���ܶ��������ñ������Լ���ָ�룬��Ȼ�ͻ�����ݹ���ȥ
for(cur = head; cur; cur = cur->next) //����������д�������Ե�������ʹ��
{
}

4��
for(int i = a; i <= b; ++i)
//  ���ֱ�����i�������[a, b]֮��ı���

for(int i = 0; i < size; ++i)
//  ���������a[i]�����a���±���[0, size)֮��ı���

for(int i = value; i; i /=s) i % s
//  ��λ������i%s�������λ�ı�����


int count;
for(int i = value; i; i /= 2)
{
	count += i % 2;
}


//////////////////////////////////////////////////////////////////////////

4�����ս�
https://www.nowcoder.com/practice/72a99e28381a407991f2c96d8cb238ab?tpId=49&&tqId=29305&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

��Ŀ����
С�����ڹ�˾Ҫ�����ս�����С��ǡ�û������߸�������Ҫ�ڹ�˾����ϲ���һ���齱��Ϸ����Ϸ��һ��6*6�������Ͻ��У��������36����ֵ���ȵ����ÿ��С���������������һ���������Ҫ�����Ͻǿ�ʼ��Ϸ��ÿ��ֻ�����»��������ƶ�һ�����������½�ֹͣ��һ·�ϵĸ����������С�������õ��������һ���㷨ʹС���õ���ֵ��ߵ����

����һ��6*6�ľ���board������ÿ��Ԫ��Ϊ��Ӧ���ӵ������ֵ,���Ͻ�Ϊ[0,0],�뷵���ܻ�õ�����ֵ����֤ÿ�������ֵ����100С��1000��

class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
        int length = board.size();
        int wideth = board[0].size();
        vector<vector<int>> allPrice;
        for (int i = 0; i < length; i++)
        {
            vector<int> tmp(wideth, 0);
            allPrice.push_back(tmp);
        }
        allPrice[0][0] = board[0][0];
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < wideth; j++)
            {
                //�����������꣬�����κδ���
                if (i == 0 && j == 0)
                    continue;
                //��������е��ٽ�ߣ�Ҳ���ǵ�һ�У���ô��ֻ��������
                //�����ߵ�ʱ��õ��Ҫ�������ֵ��������
                else if (i == 0)
                {
                    allPrice[i][j] = allPrice[i][j - 1] + board[i][j];
                }
                //��������е��ٽ�ߣ�Ҳ���ǵ�һ�У���ô��ֻ��������
                //�����ߵ�ʱ��õ��Ҫ�������ֵ��������
                else if (j == 0)
                {
                    allPrice[i][j] = allPrice[i - 1][j] + board[i][j];
                }
                else
                {
                    //��ȥ�����ٽ�ߣ�ʣ�µľ��Ǽ��������ߣ�Ҳ�������ߣ�
                    //��ʱ���Ҫ�����ߵ���ǰ������п��ܵ������Ҳ�����ߵ���ǰ��
                    //����·���ĺ��ǲ�����Щ���е���õ�·�����������ˡ�
                    allPrice[i][j] = max(allPrice[i][j - 1], allPrice[i - 1][j]) + board[i][j];
                }
            }
        }
        // �������һ��������ֵ�����ͱ�ʾ�����Ͻ��ߵ����½ǵ������
        return allPrice[length - 1][wideth - 1];
    }
};


5����ˮƿ
https://www.nowcoder.com/practice/fe298c55694f4ed39e256170ff2c205f?tpId=37&&tqId=21245&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

��Ŀ����
������һ�������⣺��ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��С��������ʮ������ˮƿ���������Ի�����ƿ��ˮ�ȣ�������5ƿ���������£�����9����ƿ�ӻ�3ƿ��ˮ���ȵ�3ƿ���ģ������Ժ�4����ƿ�ӣ���3���ٻ�һƿ���ȵ���ƿ���ģ���ʱ��ʣ2����ƿ�ӡ�Ȼ�������ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ������Ժ���3����ƿ�ӻ�һƿ���Ļ����ϰ塣���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ� 
��������:
�����ļ�������10��������ݣ�ÿ������ռһ�У�������һ��������n��1<=n<=100������ʾС�����ϵĿ���ˮƿ����n=0��ʾ�����������ĳ���Ӧ��������һ�С�

�������:
����ÿ��������ݣ����һ�У���ʾ�����Ժȵ���ˮƿ�������һƿҲ�Ȳ��������0��

ʾ��1
����
3
10
81
0
���
1
5
40

#include<iostream>
#include<string>
using namespace std;
int calculateNum(int num)
{
    //�ܶһ���
    int sum = 0;
    while (num > 1)
    {
        //ÿ��ƿ��һƿ
        int result = num / 3;
        //ʣ�಻����ƿ���ȱ���
        int reminder = num % 3;
        sum = sum + result;
        //��һ�ο��Զһ��Ŀ�ƿ
        num = result + reminder;
        if (num == 2)
        {
            ++sum;
            break;
        }
    }
    return sum;
}
int main()
{
    int number;
    while (cin >> number)
    {
        cout << calculateNum(number) << endl;
    }
    return 0;
}



5���ַ�����ת
https://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&&tqId=21235&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

��Ŀ����
д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ��������磺
��������:
����N���ַ�

�������:
������ַ�����ת����ַ���

ʾ��1
����
abcd
���
dcba

#include<string>
#include<iostream>
using namespace std;
string reverseString(string s) {
    if (s.empty())
        return s;
    size_t start = 0;
    size_t end = s.size() - 1;
    while (start < end)
    {
        swap(s[start], s[end]);
        ++start;
        --end;
    }
    return s;
}
int main()
{
    string s;
    getline(cin, s);
    cout << reverseString(s) << endl;
    return 0;
}



6��ϴ��
https://www.nowcoder.com/practice/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0?tpId=85&&tqId=29848&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

��Ŀ����
ϴ����������ʮ�ֳ�����������Ҫдһ������ģ��ϴ�ƵĹ��̡� ������Ҫϴ2n���ƣ����ϵ��������ǵ�1�ţ���2�ţ���3��һֱ����2n�š����ȣ����ǰ���2n���Ʒֳ����ѣ��������ŵ�1�ŵ���n�ţ��ϰ�ѣ����������ŵ�n+1�ŵ���2n�ţ��°�ѣ������žͿ�ʼϴ�ƵĹ��̣��ȷ������ֵ����һ���ƣ��ٷ������ֵ����һ���ƣ����ŷ������ֵĵ����ڶ����ƣ��ٷ������ֵĵ����ڶ����ƣ�ֱ�����������ֵĵ�һ���ơ����Ű��ƺϲ������Ϳ����ˡ� ������6���ƣ��ʼ�Ƶ�������1,2,3,4,5,6�����ȷֳ����飬��������1,2,3����������4,5,6����ϴ�ƹ����а�˳�������6,3,5,2,4,1�������������ٴκϳ�һ����֮�����ǰ��մ������µ�˳�������ƣ��ͱ��������1,4,2,5,3,6�� ���ڸ���һ��ԭʼ���飬������⸱��ϴ��k��֮��������µ����С�
��������:
��һ��һ����T(T �� 100)����ʾ��������������ÿ�����ݣ���һ��������n,k(1 �� n,k �� 100)��������һ����2n����a1,a2,...,a2n(1 �� ai �� 1000000000)����ʾԭʼ������ϵ��µ����С�
�������:
����ÿ�����ݣ����һ�У����յ����С�����֮���ÿո��������Ҫ����ĩ�������Ŀո�
ʾ��1
����
3 3 1 1 2 3 4 5 6 3 2 1 2 3 4 5 6 2 2 1 1 1 1
���
1 4 2 5 3 6 1 5 4 3 2 6 1 1 1 1

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int T, n, k;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        int num = 2 * n;
        vector<int> table(num);
        for (int i = 0; i < num; ++i)
            cin >> table[i];
        //ϴk����
        while (k--)
        {
            vector<int> n1(table.begin(), table.end());
            for (int i = 0; i < n; ++i)
            {
                //�����ǰ��С�ڵ���n���������֣��������´γ��ֵ�λ���� 2*��ǰλ��
                //��֮��Ӧ�ĵ�ǰλ�� + n���������֣�����,�����´γ��ֵ�λ���� 2*��ǰλ�� + 1
                table[2 * i] = n1[i];
                table[2 * i + 1] = n1[i + n];
            }
        }
        for (int i = 0; i < num - 1; ++i)
            cout << table[i] << " ";
        cout << table[num - 1] << endl;
    }
    return 0;
}


7��MP3���λ��
https://www.nowcoder.com/practice/eaf5b886bd6645dd9cfb5406f3753e15?tpId=37&&tqId=21287&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

��������:
����˵����
1 �����������
2 �������� U����D

�������:
���˵��
1 �����ǰ�б�
2 �����ǰѡ�и���

ʾ��1
����
10
UUUU
���
7 8 9 10
7

#include <iostream>
#include <string>
using namespace std;
int main(){
    //��������
    int n;
    //����
    string order;
    while (cin >> n >> order)
    {
        //��n�׸������1��n , numΪ��굱ǰ���ڸ����ı��,firstΪ��ǰ��Ļ��ʾҳ�ĵ�һ�׸����ı��
        int num = 1, first = 1;
        if (n <= 4) //��������������4ʱ�����и���һҳ������ʾ�꣬���跭ҳ��firstʼ�ղ���
        {
            for (int i = 0; i < order.size(); i++)
            {
                if (num == 1 && order[i] == 'U')
                    num = n;
                else if (num == n && order[i] == 'D')
                    num = 1;
                else if (order[i] == 'U')
                    num--;
                else
                    num++;
            }
            for (int i = 1; i <= n - 1; i++)
                cout << i << ' ';
            cout << n << endl;
            cout << num << endl;
        }
        else //������������4ʱ����ʾ��ȫ���и�����Ҫ��ҳ����Ļ������ʾ4�׸���
        {
            for (int i = 0; i < order.size(); i++)
            {
                if (first == 1 && num == 1 && order[i] == 'U')
                { first = n - 3; num = n; } //���ⷭҳ1
                else if (first == n - 3 && num == n && order[i] == 'D')
                { first = 1; num = 1; } //���ⷭҳ2
                else if (first != 1 && num == first && order[i] == 'U')
                { first--; num--; } //һ�㷭ҳ1
                else if (first != n - 3 && num == first + 3 && order[i] == 'D')
                { first++; num++; } //һ�㷭ҳ2
                else if (order[i] == 'U')
                    num--; //�������1
                else
                    num++; //�������2
            }
            for (int i = first; i < first + 3; i++)
                cout << i << ' ';
            cout << first + 3 << endl;
            cout << num << endl;
        }
    }
    return 0;
}


8��С�׵�����֮·
https://www.nowcoder.com/practice/fe6c73cb899c4fe1bdd773f8d3b42c3d?tpId=49&&tqId=29329&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

��Ŀ����
С�׾���������������Ϸ.��һ��,������һ�������������Ϸ,���Ľ�ɫ�ĳ�ʼ����ֵΪ a.�ڽ�������һ��ʱ����,��������������n������,ÿ������ķ�����Ϊb1,b2,b3...bn. ��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc,��ô���������ɴ�ܹ���,�� ��ʹ���Լ�������ֵ����bi;���bi����c,����Ҳ�ܴ�ܹ���,����������ֵֻ������bi ��c�����Լ��.��ô��������,��һϵ�еĶ�����,С�׵���������ֵΪ����?
��������:
����ÿ������,��һ������������n(1��n<100000)��ʾ�����������a��ʾС�׵ĳ�ʼ����ֵ.
�ڶ���n������,b1,b2...bn(1��bi��n)��ʾÿ������ķ�����
�������:
����ÿ������,���һ��.ÿ�н�����һ������,��ʾС�׵���������ֵ

ʾ��1
����
3 50
50 105 200
5 20
30 20 15 40 100
���
110
205

#include <iostream>
#include <vector>
using namespace std;

int ConventionNumber(int a, int b)//�����Լ��
{
    int c;
    while(c = a % b)
    {
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n, ret;
    while(cin >> n >> ret)
    {
        vector<int> v(n);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for(int i = 0; i < n; i++)
        {
            if(v[i] <= ret)
            {
                ret += v[i];
            }
            else
            {
                ret += ConventionNumber(v[i], ret);
            }
        }
        cout << ret << endl;
    }
    return 0;
}