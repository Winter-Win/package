1、手套
https://www.nowcoder.com/practice/365d5722fff640a0b6684391153e58d8?tpId=49&&tqId=29337&rp=1&ru=/

题目描述
在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。

给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。

测试样例：
4,[0,7,1,6],[1,5,0,6]
返回：10(解释：可以左手手套取2只，右手手套取8只)

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        // 【题目解析】：
        // 本题的意思是随意取出的手套至少可以形成一组组合的最少手套数量。
        // 题目给的两个数组对应位置表示同一种颜色的左右手套数量。 
        // 【解题思路】：
        // 对于非0递增序列a1,a2...an，要想最终取值覆盖每一个种类 n = sum(a1...an) - a1 +1
        // （也就是总数减去最小值之后加一） 所以对于左右手手套颜色都有数量的序列，
        // 想要覆盖每一种颜色，则最小数量leftsum = 左边数量和 - 左边最小值 + 1，
        // rightsum =右边数量和 - 右边的最小值 + 1。而对于有0存在的，则需要做累加，保证覆盖每一种颜色。
        
        int left_sum = 0, left_min = INT_MAX;
        int right_sum = 0, right_min = INT_MAX;
        int sum = 0;
        //遍历每种颜色的左右手套序列
        for(int i = 0; i < n; ++i)
        {
            // 对于存在为0的颜色手套，累加
            if(left[i] * right[i] == 0)
                sum += left[i] + right[i];
            // 对于左右手都有颜色的，执行累加 - 最小值 + 1
            // 找到最小值和总数
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
        // 有手套的结果 + 存在0的 + 1
        return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
    }
};

2、扑克牌大小
https://www.nowcoder.com/practice/0a92c75f5d6b4db28fcfa3e65e5c9b3f?tpId=49&&tqId=29277&rp=1&ru=/

题目描述
扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:) 
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER 
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR

基本规则：
（1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
（3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。

答案提示：
（1）除了炸弹和对王之外，其他必须同类型比较。
（2）输入已经保证合法性，不用检查输入是否是合法的牌。
（3）输入的顺子已经经过从小到大排序，因此不用再排序了.
输入描述:
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如4 4 4 4-joker JOKER。
输出描述:
输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。
示例1
输入
4 4 4 4-joker JOKER
输出
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
        //王炸最大，直接输出
        if (Poker.find("joker JOKER") != -1)
            cout << "joker JOKER" << endl;
        else
        {
            int dash = Poker.find('-');
            // 分牌
            string P1 = Poker.substr(0, dash);
            string P2 = Poker.substr(dash + 1);
            
            //  记录空格的次数
            int num1 = count(P1.begin(), P1.end(), ' ');
            int num2 = count(P2.begin(), P2.end(), ' ');
            
            //  拿到第一张牌，便于后面的比较
            string first1 = P1.substr(0, P1.find(' '));
            string first2 = P2.substr(0, P2.find(' '));
            string str = "345678910JQKA2jokerJOKER";
            if (num1 == num2)
            {
                //只要牌数相等，则第一张牌大的即为大
                if (str.find(first1) >str.find(first2))
                    cout << P1 << endl;
                else
                    cout << P2 << endl;
             }
             else
             {
                //牌数不相同，说明类型不同,只有炸弹可以和其它牌比较
                //其它类型都是错误的
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


3、iNOC产品部-杨辉三角的变形
https://www.nowcoder.com/practice/8ef655edf42d4e08b44be4d777edbf43?tpId=37&amp;&amp;tqId=21276&amp;rp=1&amp;ru

题目描述
            1

         1  1  1

      1  2  3  2  1

   1  3  6  7  6  3  1

1  4  10 16 19  16 10  4  1

以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。

求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。

 

输入n(n <= 1000000000)
输入描述:
输入一个int整数

输出描述:
输出返回的int值

示例1
输入
4
输出
3


#include <iostream>
#include <vector>

using namespace std;

// 1
// 1  1  1
// 1  2  3  2  1
// 1  3  6  7  6  3  1
// 1  4  10 16 19 16 10  4  1

//  按照题目意思，可以发现第n行有2n -1个元素，第i,j元素等于上一行第j -2,j -1,j三列元素之和
//  每一行的第一列和最后一列都为1，如果是第二列，则只是两个元素之和。

int main()
{
    int n;
    while(cin >> n)
    {
        int m = (n << 1) - 1;
        //  将整个二维数组开辟出来全部先初始化为0
        vector<vector<int> > vv(n, vector<int>(m, 0));
        //  将第一个数置为1
        vv[0][0] = 1;
        for(int i = 1; i < n; ++i)
        {
            //  将每行的对应的首尾数都置为1
            vv[i][0] = vv[i][2 * i] = 1;
            for(int j = 1; j < 2 * i; ++j)
            {
                //  如果只是第二列，只需要两个元素之和
                if(j == 1)
                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
                else
                    //  等于上一行的j - 2, j - 1, j三列元素之和
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
        //  遍历完了，说明没找到
        if(k == m)
            cout << -1 << endl;
    }
    return 0;
}
