﻿1、删除链表中等于给定值 val 的所有节点。https://leetcode-cn.com/problems/remove-linked-list-elements/
示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

C版本：
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
            //如果prev还是为空的话，说明此时是在第一个
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


2、反转一个单链表。https://leetcode-cn.com/problems/reverse-linked-list/
示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

C版本：
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* newnode = NULL;
    
    while(cur)
    {
        struct ListNode* next = cur->next;
        cur->next = newnode;
        newnode = cur;
        cur = next;
    }
    return newnode;
}


C版本：
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    struct ListNode *n1, *n2, *n3;
    n1 = head;
    n2 = n1->next;
    n3 = n2->next;
    n1->next = NULL;
    while(n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if(n3)
        {
            n3 = n3->next;
        }
    }
    return n1;
}

3、给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
https://leetcode-cn.com/problems/middle-of-the-linked-list/description/
示例 1：
输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.

示例 2：
输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    //快慢指针
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}



4、输入一个链表，输出该链表中倒数第k个结点。
https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        struct ListNode* fast = pListHead;
        struct ListNode* slow = pListHead;
        while(k--)
        {
            if(fast)
                fast = fast->next;
            else
                return NULL;
        }
        
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};



5、将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
https://leetcode-cn.com/problems/merge-two-sorted-lists/
示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL)
        return l2;
    
    else if(l2 == NULL)
        return l1;
    
    struct ListNode* head, *tail;
    if(l1->val < l2->val)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }
    
    //拿小的尾插
    tail = head;
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    if(l1 != NULL)
        tail->next = l1;
    
    if(l2 != NULL)
        tail->next = l2;
    
    return head;
}



6. 字符串相加
https://leetcode-cn.com/problems/add-strings/
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
注意：
（1）num1 和num2 的长度都小于 5100.
（2）num1 和num2 都只包含数字 0-9.
（3）num1 和num2 都不包含任何前导零。
（4）你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
class Solution {
public:
    string addStrings(string num1, string num2) {
        //从后往前加
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int val1 = 0, val2 = 0, next = 0;
        string addret;
        while(end1 >= 0 || end2 >= 0)
        {
            //依次从里面拿出来
            if(end1 >= 0) {
                val1 = num1[end1--] - '0';
            }
            else {
                val1 = 0;
            }
            
            if(end2 >= 0) {
                val2 = num2[end2--] - '0';
            }
            else {
                val2 = 0;
            }
            
            //将拿出来的两个数加起来
            int valret = val1 + val2 + next;
            if(valret > 9) {//判断进位
                next = 1;
                valret -= 10;
            }
            else {//这一步要处理，每次都得更新为零，也可以在后面处理
                next = 0;
            }
            
            //addret.insert(addret.begin(), valret + '0');//不建议，这是一个n方的时间复杂度
            addret += (valret + '0');
        }
        
        //还在大循环里面，如果next == 1，说明进位上来的，所以在前面出入进位的‘1’
        if(next == 1){
            //addret.insert(addret.begin(), '1');
            addret += '1';
        }
        
        reverse(addret.begin(), addret.end());
        return addret;
    }
};


7. 杨辉三角
https://leetcode-cn.com/problems/pascals-triangle/
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        vv.resize(numRows);
        
        for(size_t i = 0; i < numRows; ++i)
        {
            vv[i].resize(i+1, 0);
            vv[i][0] = 1;
            vv[i][i] = 1;
        }
        
        for(size_t i = 0; i < vv.size(); ++i)
        {
            for(size_t j = 0; j < vv[i].size(); ++j)
            {
                if(vv[i][j] != 1)
                    vv[i][j] = vv[i-1][j-1] + vv[i-1][j];
            }
        }
        
        return vv;
    }
};


8. 合法括号序列判断
https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&&tqId=11039&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。

测试样例：
"(()())",6
返回：true
测试样例：
"()a()()",7
返回：false
测试样例：
"()(()()",7
返回：false

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        stack<char> st;
        int i = 0;
        int flag = 0;
        for(auto ch : A)
        {
            if(ch != ')' && ch == '(')
            {
                st.push(ch);
            }
            else
            {
                if(!st.empty() && ch == ')' && st.top() == '(')
                {
                    st.pop();
                }
                else
                    return false;
            }
        }
        return true;
    }
};



9、字符串通配符
https://www.nowcoder.com/questionTerminal/43072d50a6eb44d2a6c816a283b02036

问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
？：匹配1个字符

输入：
通配符表达式；
一组字符串。

输出：
返回匹配的结果，正确输出true，错误输出false

输入描述:
先输入一个带有通配符的字符串，再输入一个需要匹配的字符串

输出描述:
返回匹配的结果，正确输出true，错误输出false

示例1
输入
te?t*.*
txt12.xls
输出
false

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string  s1, s2;
	while (cin >> s1 >> s2)
	{
		size_t i = 0;
		bool flag = false;
		while (i < s1.size())
		{
			if (s1[i] == s2[i])
				i++;
			else if (s1[i] == '?')
				i++;
			else if (s1[i] == '*')
			{
				if (i == s1.size() - 1)
				{
					cout << "true" << endl;
					flag = true;
					break;
				}
				else if (i < s1.size() - 1)
					i++;
			}
			else if (s1[i] != s2[i] && s1[i] != '*' && s1[i] != '?')
			{
				cout << "false" << endl;
				flag = true;
				break;
			}
		}
		if (flag == false)
			cout << "true" << endl;
	}
	return 0;
}




10、输入一个链表，反转链表后，输出新链表的表头。
https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
（尝试新方法）-->容器辅助
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        vector<int> lt;
        struct ListNode* cur = pHead;
        while(cur)
        {
            lt.push_back(cur->val);
            cur = cur->next;
        }
        
        struct ListNode* ret = pHead;
        auto it = lt.rbegin();
        while(it != lt.rend())
        {
            ret->val = *it;
            ret = ret->next;
            it++;
        }
        return pHead;
    }
};



11、
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&&tqId=11039&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking

测试样例：
"(()())",6
返回：true
测试样例：
"()a()()",7
返回：false
测试样例：
"()(()()",7
返回：false

/*
用栈结构实现，栈中存放左括号，当遇到右括号之后，检查栈中是否有左括号
如果有则出栈，如果没有，则说明不匹配。
*/

class Parenthesis {
public:
bool chkParenthesis(string A, int n) {
        // write code here
        stack<char> sc;
        for (auto ele : A) 
        {
            switch (ele) 
            {
                case '(':
                    sc.push(ele);
                    break;
                case ')':
                {
                    if (sc.empty() || sc.top() != '(')
                        return false;
                    else
                        sc.pop();
                }
                    break;
                default:
                    return false;
            }
        }
        return true;
    }
};




12、
对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。
https://www.nowcoder.com/practice/e1bb714eb9924188a0d5a6df2216a3d1?tpId=8&&tqId=11055&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking


测试样例：
[[1,0,1],[1,-1,-1],[1,-1,0]]
返回：true

/*
井字棋，是一种在3*3格子上进行的连珠游戏，三个相同就代表获胜。
所以有四种情况表示当前玩家获胜，1代表当前玩家棋子
1. 行全为1， 即行的和为3
2. 列全为1， 列的和为3
3. 主对角全为1， 对角和为3
4. 副对角全为1， 对角和为3
如果扩展为N*N的话，判断和是否等于N
下面代码适用任何情况
*/
class Board {
public:
bool checkWon(vector<vector<int> > board) {
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
    else
        return false;
    }
};




13、二叉树的前序遍历
https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
给定一个二叉树，返回它的 前序 遍历。
示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        
        //开始访问一课树
        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                v.push_back(cur->val);
                cur = cur->left;
            }
            
            TreeNode* top = st.top();
            st.pop();
            cur = top->right;
        }
        return v;
    }
};



14、组队竞赛
https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false

牛牛举办了一次编程比赛,参加比赛的有3*n个选手,每个选手都有一个水平值a_i.现在要将这些选手进行组队,一共组成n个队伍,即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
例如:
一个队伍三个队员的水平值分别是3,3,3.那么队伍的水平值是3
一个队伍三个队员的水平值分别是3,2,3.那么队伍的水平值是3
一个队伍三个队员的水平值分别是1,5,2.那么队伍的水平值是2
为了让比赛更有看点,牛牛想安排队伍使所有队伍的水平值总和最大。
如样例所示:
如果牛牛把6个队员划分到两个队伍
如果方案为:
team1:{1,2,5}, team2:{5,5,8}, 这时候水平值总和为7.
而如果方案为:
team1:{2,5,8}, team2:{1,5,5}, 这时候水平值总和为10.
没有比总和为10更大的方案,所以输出10.

输入描述:
输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)

第二行包括3*n个整数a_i(1 ≤ a_i ≤ 10^9),表示每个参赛选手的水平值.


输出描述:
输出一个整数表示所有队伍的水平值总和最大值.
示例1
输入
2
5 2 8 5 1 5
输出
10


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> v(3*n);
        for(int i = 0; i < 3*n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        //每次选择尽可能大的，但是 又不能直接是最大的，所以只能退而求其次,跳一个
        //从n开始，不可能是最小的那n个，但是也不可能是最大的那个
        long sum = 0;
        for(int i = n; i < 3*n-1; i+=2)
        {
            sum += v[i];
        }
        cout << sum << endl;
    }
    return 0;
}


15、删除公共字符
https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

题目描述
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
输入描述:
每个测试输入包含2个字符串
输出描述:
输出删除后的字符串
示例1
输入
复制
They are students. aeiou
输出
复制
Thy r stdnts.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    
    //方法一：直接for循环遍历两个字符串，删除相对应的字符，但是时间复杂度很高
    //方法二：利用哈希映射思想，先统计str2中的字符，字符分为可见不可见字符，256个
    int arr[256] = {0};
    for(size_t i = 0; i < str2.size(); i++)
    {
        arr[str2[i]]++;
    }
    
    //再遍历str1,如果在str2中没有出现的话，arr对应的位置应该是0,就可以将其取出来
    //建议不使用erase,边遍历边删除容易出问题
    string ret;
    for(size_t i = 0; i < str1.size(); ++i)
    {
        if(arr[str1[i]] == 0)
        {
            ret += str1[i];
        }
    }
    cout << ret << endl;
    return 0;
}


16、替换空格
https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

class Solution {
public:
	void replaceSpace(char *str,int length) {
        string s(str);
        string ret;
        auto it = s.begin();
        while(it != s.end())
        {
            if(*it == ' ')
                ret += "%20";
            ret += *it;
            it++;
        }
        int i = 0;
        while((i = ret.find(' ',i)) > -1)
            ret.erase(i, 1);
        strcpy(str, ret.c_str());
	}
};



class Solution {
public:
	void replaceSpace(char *str,int length) {
        string s(str);
        int i = 0;
        while((i = s.find(' ',i)) > -1)
        {
            s.erase(i, 1);
            s.insert(i, "%20");
        }
        strcpy(str, s.c_str());
	}
};


16、合并两个排序链表
https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        
        struct ListNode* newnode;
        //定头,链表也要向后移动
        if(pHead1->val <= pHead2->val)
        {
            newnode = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            newnode = pHead2;
            pHead2 = pHead2->next;
        }
        //合并
        struct ListNode* cur = newnode;
        while(pHead1 && pHead2)
        {
            if(pHead1->val <= pHead2->val)
            {
                cur->next = pHead1;
                pHead1 = pHead1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = pHead2;
                pHead2 = pHead2->next;
                cur = cur->next;
            }
        }
        //说明短的走完了
        if(pHead1 == NULL)
            cur->next = pHead2;
        if(pHead2 == NULL)
            cur->next = pHead1;
        
        return newnode;
    }
};


17、二维数组中的查找
https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //只需要负责找到在不在就行
        //利用二维数组由上到下，由左到右递增的规律，
        //那么选取右上角或者左下角的元素array[row][col]与target进行比较，
        //当target小于元素array[row][col]时，那么target必定在元素array所在行的左边,
        //即col--；
        //当target大于元素array[row][col]时，那么target必定在元素array所在列的下边,
        //即row++；
        int row = array.size(); //有多少行
        int col = array[0].size(); //有多少列
        // 从左下角判断
        int i = row - 1;
        int j = 0;
        while(i >= 0 && j < col) // 保证在数组范围内
        {
            if(target < array[i][j]) // 元素较小，往上找
                i--;
            else if(target > array[i][j]) //元素较大，往右找
                j++;
            else // 找到了
                return true;
        }
        // 说明没找到
        return false;
    }
};


18、第一个只出现一次的字符
https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.length()==0)
            return -1;
        int hasharray[256] = {0};
        size_t i = 0;
        for(i = 0; i < str.size(); ++i)
            hasharray[str[i]]++;
        
        i = 0;
        for(i = 0; i < str.size(); ++i)
        {
            if(hasharray[str[i]] == 1)
                return i;
        }
        
        return -1;
    }
};


19、斐波那契数列
https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39

class Solution {
public:
    int Fibonacci(int n) {
        //考虑负数
        if(n < 0)
            return 0;
        
        //建议不使用递归
        int first = 0;
        int second = 1;
        /*
        int ret = n;
        for(int i = 2; i<=n; i++)
        {
            ret = first + second;
            first = second;
            second = ret;
        }
        return ret;
        */
        
        while(n--)
        {
            second = second + first;  //第三个值给现在的第二个
            first = second - first;  //原来的第二个值给现在的第一个
        }
        return first;
    }
};

20、树的子结构
https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool IsHasSubtree(TreeNode* pRootA, TreeNode* pRootB)
    {
        //如果B树先结束 为空，说明是子树
        if(pRootB == NULL)
            return true;
        
        //如果A树先结束 为空，则不是子树
        if(pRootA == NULL)
            return false;
        
        //直接判断是否相等，然后递归子树判断
        if(pRootA->val == pRootB->val)
            return IsHasSubtree(pRootA->left, pRootB->left) 
                && IsHasSubtree(pRootA->right, pRootB->right);
        else
            return false;
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL) //A树为空，肯定无法有子树
            return false;
        
        if(pRoot2 == NULL) //B树为空，不是子树
            return false;
        
        //走到这儿，说明都不为空
        return IsHasSubtree(pRoot1, pRoot2) 
            || HasSubtree(pRoot1->left, pRoot2) 
            || HasSubtree(pRoot1->right, pRoot2);
    }
};