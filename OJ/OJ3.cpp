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

//             1
//          1  1  1
//       1  2  3  2  1
//    1  3  6  7  6  3  1
// 1  4  10 16 19 16 10 4  1

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


4、超长整数相加
https://www.nowcoder.com/practice/5821836e0ec140c1aa29510fd05f45fc?tpId=37&&tqId=21301&rp=1&ru=/

题目描述
请设计一个算法完成两个超长正整数的加法。

接口说明
 /*
 请设计一个算法完成两个超长正整数的加法。
 输入参数：
 String addend：加数
 String augend：被加数
 返回值：加法结果
 */
 public String AddLongInteger(String addend, String augend)
 {
     /*在这里实现功能*/
	return null;     
 }

输入描述:
输入两个字符串数字

输出描述:
输出相加后的结果，string型

示例1
输入
99999999999999999999999999999999999999999999999999
1
输出
100000000000000000000000000000000000000000000000000

//  加法运算，每一位的值等于当前对应位的两数之和+进位。由于是加法，所以当前位的和最多是19（9 + 9 + 进位1)，
//  所以产生的进位最多为1。故
//  第一步：计算对应位的和，对应位相加 + 上一位的进位
//  第二步：更新当前位的值， 和 % 10 ，把值转成字符（和 -'0'）存入字符结果中
//  第三步：更新进位， 和 / 10， 然后计算下一位的值
//  最后一步：如果计算完之后，进位为1，说明最高位产生了进位，所以需要再加一位，才是最后的结果。结果产生之
//  后，需要逆置，得到最终结果。

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
string addStrings(string num1, string num2)
{
    //由低位向高位相加
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    string result = "";
    //当前位的相加结果
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
        //当前为的最大值不大于10
        result += (char)(carry % 10 + '0');
        //如果大于10,向上进一位
        carry /= 10;
        i--;
        j--;
    }
    //相加完之后，如果还有进位，则再加1
    if (carry == 1)
    { 
        result += '1';
    }
    //整体逆置
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

1、定义一个拥有五个元素的数组，每个元素都是一个指向含有五个返回值为int，参数为两个int的函数指针的数组的指针
int *(*p[5][5])(int, int);

//  对于定义多级指针，几个 * 用几个 p ，避免自己搞混，简单说，一个*可以抵消一个p 

2、所有的解引用操作符对于作用于函数指针，都视为无效，有没有*,都不影响，函数指针只是一个样本上的指针，不是实际的指针
int （*pfunc）(int, int) = add;
//  add此时没有空间，赋值过去的只是一个假的地址
//  add前面加不加&符号，都视为无效

3、
struct list{
  int data;
  struct list * next;
};
//  * 不能丢，自引用必须是自己的指针，不然就会无穷递归下去
for(cur = head; cur; cur = cur->next) //遍历链表新写法，可以当成数组使用
{
}

4、
for(int i = a; i <= b; ++i)
//  数字遍历：i完成了在[a, b]之间的遍历

for(int i = 0; i < size; ++i)
//  数组遍历：a[i]完成了a的下标在[0, size)之间的遍历

for(int i = value; i; i /=s) i % s
//  数位遍历：i%s完成了数位的遍历，


int count;
for(int i = value; i; i /= 2)
{
	count += i % 2;
}


//////////////////////////////////////////////////////////////////////////

4、年终奖
https://www.nowcoder.com/practice/72a99e28381a407991f2c96d8cb238ab?tpId=49&&tqId=29305&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

题目描述
小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，游戏在一个6*6的棋盘上进行，上面放着36个价值不等的礼物，每个小的棋盘上面放置着一个礼物，他需要从左上角开始游戏，每次只能向下或者向右移动一步，到达右下角停止，一路上的格子里的礼物小东都能拿到，请设计一个算法使小东拿到价值最高的礼物。

给定一个6*6的矩阵board，其中每个元素为对应格子的礼物价值,左上角为[0,0],请返回能获得的最大价值，保证每个礼物价值大于100小于1000。

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
                //如果是起点坐标，不做任何处理。
                if (i == 0 && j == 0)
                    continue;
                //如果走在行的临界边，也就是第一行，那么他只能向右走
                //向右走的时候该点就要将后面的值加起来。
                else if (i == 0)
                {
                    allPrice[i][j] = allPrice[i][j - 1] + board[i][j];
                }
                //如果走在列的临界边，也就是第一列，那么他只能向下走
                //向下走的时候该点就要将上面的值加起来。
                else if (j == 0)
                {
                    allPrice[i][j] = allPrice[i - 1][j] + board[i][j];
                }
                else
                {
                    //除去两个临界边，剩下的就是既能向右走，也能向下走，
                    //这时候就要考虑走到当前点的所有可能得情况，也就是走到当前点
                    //各自路径的和是不是这些所有到达该点路径当中最大的了。
                    allPrice[i][j] = max(allPrice[i][j - 1], allPrice[i - 1][j]) + board[i][j];
                }
            }
        }
        // 返回最后一个坐标点的值，它就表示从左上角走到右下角的最大奖励
        return allPrice[length - 1][wideth - 1];
    }
};


5、汽水瓶
https://www.nowcoder.com/practice/fe298c55694f4ed39e256170ff2c205f?tpId=37&&tqId=21245&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

题目描述
有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？ 
输入描述:
输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=100），表示小张手上的空汽水瓶数。n=0表示输入结束，你的程序不应当处理这一行。

输出描述:
对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。

示例1
输入
3
10
81
0
输出
1
5
40

#include<iostream>
#include<string>
using namespace std;
int calculateNum(int num)
{
    //总兑换数
    int sum = 0;
    while (num > 1)
    {
        //每三瓶换一瓶
        int result = num / 3;
        //剩余不足三瓶的先保留
        int reminder = num % 3;
        sum = sum + result;
        //下一次可以兑换的空瓶
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



5、字符串反转
https://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&&tqId=21235&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

题目描述
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：
输入描述:
输入N个字符

输出描述:
输出该字符串反转后的字符串

示例1
输入
abcd
输出
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



6、洗牌
https://www.nowcoder.com/practice/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0?tpId=85&&tqId=29848&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

题目描述
洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。 现在需要洗2n张牌，从上到下依次是第1张，第2张，第3张一直到第2n张。首先，我们把这2n张牌分成两堆，左手拿着第1张到第n张（上半堆），右手拿着第n+1张到第2n张（下半堆）。接着就开始洗牌的过程，先放下右手的最后一张牌，再放下左手的最后一张牌，接着放下右手的倒数第二张牌，再放下左手的倒数第二张牌，直到最后放下左手的第一张牌。接着把牌合并起来就可以了。 例如有6张牌，最开始牌的序列是1,2,3,4,5,6。首先分成两组，左手拿着1,2,3；右手拿着4,5,6。在洗牌过程中按顺序放下了6,3,5,2,4,1。把这六张牌再次合成一组牌之后，我们按照从上往下的顺序看这组牌，就变成了序列1,4,2,5,3,6。 现在给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的序列。
输入描述:
第一行一个数T(T ≤ 100)，表示数据组数。对于每组数据，第一行两个数n,k(1 ≤ n,k ≤ 100)，接下来一行有2n个数a1,a2,...,a2n(1 ≤ ai ≤ 1000000000)。表示原始牌组从上到下的序列。
输出描述:
对于每组数据，输出一行，最终的序列。数字之间用空格隔开，不要在行末输出多余的空格。
示例1
输入
3 3 1 1 2 3 4 5 6 3 2 1 2 3 4 5 6 2 2 1 1 1 1
输出
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
        //洗k次牌
        while (k--)
        {
            vector<int> n1(table.begin(), table.end());
            for (int i = 0; i < n; ++i)
            {
                //如果当前数小于等于n（即在左手），则他下次出现的位置是 2*当前位置
                //与之对应的当前位置 + n（即在右手）的牌,则他下次出现的位置是 2*当前位置 + 1
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


7、MP3光标位置
https://www.nowcoder.com/practice/eaf5b886bd6645dd9cfb5406f3753e15?tpId=37&&tqId=21287&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

输入描述:
输入说明：
1 输入歌曲数量
2 输入命令 U或者D

输出描述:
输出说明
1 输出当前列表
2 输出当前选中歌曲

示例1
输入
10
UUUU
输出
7 8 9 10
7

#include <iostream>
#include <string>
using namespace std;
int main(){
    //歌曲数量
    int n;
    //命令
    string order;
    while (cin >> n >> order)
    {
        //将n首歌曲编号1：n , num为光标当前所在歌曲的编号,first为当前屏幕显示页的第一首歌曲的编号
        int num = 1, first = 1;
        if (n <= 4) //歌曲总数不超过4时，所有歌曲一页即可显示完，不需翻页，first始终不变
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
        else //歌曲总数大于4时，显示完全所有歌曲需要翻页，屏幕总是显示4首歌曲
        {
            for (int i = 0; i < order.size(); i++)
            {
                if (first == 1 && num == 1 && order[i] == 'U')
                { first = n - 3; num = n; } //特殊翻页1
                else if (first == n - 3 && num == n && order[i] == 'D')
                { first = 1; num = 1; } //特殊翻页2
                else if (first != 1 && num == first && order[i] == 'U')
                { first--; num--; } //一般翻页1
                else if (first != n - 3 && num == first + 3 && order[i] == 'D')
                { first++; num++; } //一般翻页2
                else if (order[i] == 'U')
                    num--; //其他情况1
                else
                    num++; //其他情况2
            }
            for (int i = first; i < first + 3; i++)
                cout << i << ' ';
            cout << first + 3 << endl;
            cout << num << endl;
        }
    }
    return 0;
}


8、小易的升级之路
https://www.nowcoder.com/practice/fe6c73cb899c4fe1bdd773f8d3b42c3d?tpId=49&&tqId=29329&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

题目描述
小易经常沉迷于网络游戏.有一次,他在玩一个打怪升级的游戏,他的角色的初始能力值为 a.在接下来的一段时间内,他将会依次遇见n个怪物,每个怪物的防御力为b1,b2,b3...bn. 如果遇到的怪物防御力bi小于等于小易的当前能力值c,那么他就能轻松打败怪物,并 且使得自己的能力值增加bi;如果bi大于c,那他也能打败怪物,但他的能力值只能增加bi 与c的最大公约数.那么问题来了,在一系列的锻炼后,小易的最终能力值为多少?
输入描述:
对于每组数据,第一行是两个整数n(1≤n<100000)表示怪物的数量和a表示小易的初始能力值.
第二行n个整数,b1,b2...bn(1≤bi≤n)表示每个怪物的防御力
输出描述:
对于每组数据,输出一行.每行仅包含一个整数,表示小易的最终能力值

示例1
输入
3 50
50 105 200
5 20
30 20 15 40 100
输出
110
205

#include <iostream>
#include <vector>
using namespace std;

int ConventionNumber(int a, int b)//求最大公约数
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