1、年会抽奖
https://www.nowcoder.com/questionTerminal/610e6c0387a0401fb96675f58cda8559

今年公司年会的奖品特别给力，但获奖的规矩却很奇葩：
1. 首先，所有人员都将一张写有自己名字的字条放入抽奖箱中；
2. 待所有字条加入完毕，每人从箱中取一个字条；
3. 如果抽到的字条上写的就是自己的名字，那么“恭喜你，中奖了！”
现在告诉你参加晚会的人数，请你计算有多少概率会出现无人获奖？

输入描述:
输入包含多组数据，每组数据包含一个正整数n（2≤n≤20）。


输出描述:
对应每一组数据，以“xx.xx%”的格式输出发生无人获奖的概率。
示例1
输入
2
输出
50.00%

#include <iostream>
#include <cstdio>
int main()
{
    long long d[22] = { 0, 0, 1 }; // 错排数量，预留第一项为0，配合下文中输入的n
    long long f[22] = { 0, 1, 2 }; // 阶 乘
    for (int i = 3; i < 22; i++)
    {
        d[i] = (i - 1) * (d[i - 1] + d[i - 2]); //错排的递推公式
        f[i] = i * f[i - 1]; //阶乘的递推公式
    }
    int n;
    while (std::cin >> n)
    {
        printf("%.2f%%\n", 100.0 * d[n] / f[n]); //用100.0来把结果处理成double，保留两位小数
    }
    return 0;
}



2、被3整除
题目描述
小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。

并且小Q对于能否被3整除这个性质很感兴趣。

小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。

输入描述:
输入包括两个整数l和r(1 <= l <= r <= 1e9), 表示要求解的区间两端。
输出描述:
输出一个整数, 表示区间内能被3整除的数字个数。
示例1
输入
复制
2 5
输出
复制
3
说明
12, 123, 1234, 12345...
其中12, 123, 12345能被3整除。

/*
l<-->r 1  12  123  1234  12345  123456  1234567 ...
l----> 1   2    3     4      5       6        7 ...
l%3--> 1   2    0     1      2       0        1 ...
count->0   1    1     0      1       1        0 ...
*/

#include <iostream>

int main()
{
    int l, r;
    while(std::cin >> l >> r)
    {
        int count = 0;
        for(; l <= r; ++l)
            if(l % 3 == 2 || l % 3 == 0)
                count++;
        std::cout << count << std::endl;
    }
    return 0;
}


3、按1分类
题目描述：输入包含T个测试用例，每行为一个测试用例，一个测试用例包含N个数，
按照每个数中的二进制位为1的个数来分类，输出每组数据中可以分为几类。


#include <iostream>
#include <vector>
using namespace std;

int CountOf1(int n)
{
	int a = 0;
	while (n)
	{
		++a;
		n = (n - 1) & n;
	}
	return a;
}

int main()
{
	int T;
	while (cin >> T)
	{
		while (T--)
		{
			int N;
			cin >> N;
			vector<int> v(N);
			for (int i = 0; i < N; ++i)
				cin >> v[i];

			vector<int> count(32);
			for (int i = 0; i < N; ++i)
				count[CountOf1(v[i])]++;

			int sum = 0;
			for (int i = 0; i < 32; ++i)
			{
				if (count[i] != 0)
					++sum;
			}
			cout << sum << endl;
		}
	}
	return 0;
}



4、逆波兰表达式求值（150）
根据逆波兰表示法，求表达式的值。
有效的运算符包括?+,?-,?*,?/?。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例?1：

输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
示例?2：

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6
示例?3：

输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    int sum = 0, left = 0, right = 0;
	stack<int> st;
	for (size_t i = 0; i < tokens.size(); ++i)
	{
		string ret = tokens[i];
		if (isdigit(ret[0]) || isdigit(ret[1]))  // 判断是否数字  注意  可能是负数
			st.push(atoi(ret.c_str()));
		else
		{
				right = st.top();
				st.pop();
				left = st.top();
				st.pop();
				switch (ret[0])
				{
				case '+':
					sum = left + right;
					break;
				case '-':
					sum = left - right;
					break;
				case '*':
					sum = left * right;
					break;
				case '/':
					sum = left / right;
					break;
				default:
					break;
				}
				st.push(sum);
		}
	}
	return st.top();
    }
};