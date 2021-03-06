1、调整数组顺序使奇数位于偶数前面
https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //方法一：先将偶数都放在一个数组里，同时从原数组删除掉，最后再将其加在数组后面
        //但是时间复杂度和空间都有消耗
        vector<int> ret;
        auto it = array.begin();
        while(it != array.end())
        {
            if(*it % 2 == 0)
            {
                ret.push_back(*it);
                array.erase(it);
            }
            else
            {
                it++;
            }
        }
        
        for(auto e : ret)
        {
            array.push_back(e);
        }
    }
};



class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //方法二：类似于冒泡排序，从前往后，如果遇到相邻的先偶后奇就交换位置
        //或者从后往前冒泡，如果遇到相邻的前偶后奇就交换位置
        for(size_t i = 0; i < array.size(); ++i)
        {
            //控制j > i,减少遍历次数
            for(size_t j = array.size() - 1; j > i; --j)
            {
                if(array[j] % 2 == 1 && array[j - 1] % 2 == 0)
                    swap(array[j], array[j-1]);
            }
        }
    }
};



2、最小的K个数
https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(), input.end());
        vector<int> ret;
	//当k比数组长度还大的话，直接就是返回空，也可以包括原数组可能没数据
        if(k > input.size())
        {
            return ret;
        }
        
        for(size_t i = 0; i < k; ++i)
        {
            ret.push_back(input[i]);
        }
        return ret;
    }
};


3、旋转数组的最小数字
https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;
        //简单粗暴，直接找最小值，先排序，判断第一个数
        sort(rotateArray.begin(), rotateArray.end());
        return rotateArray[0];
    }
};



class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;
        //直接排序的话，底层用的是快排，时间复杂度平均情况为 NlogN
        //使用二分查找思想，时间复杂度 logN
        //下面这个方法是直接查找最小数字的
        int left = 0;
        int right = rotateArray.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(rotateArray[mid] > rotateArray[right]) // 说明一定在右边
                left = mid + 1;
            else if(rotateArray[mid] == rotateArray[right]) //此时最小数字不好判断在mid左边还是右边,这时只好一个一个试 
                --right;
            else //如果待查询的范围最后只剩两个数，那么mid 一定会指向下标靠前的数字
                right = mid;
        }
        return rotateArray[left];
    }
};



class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;
        //直接排序的话，底层用的是快排，时间复杂度平均情况为 NlogN
        //使用二分查找思想，时间复杂度 logN
        //下面这个方法判断区间是否是递增区间的
        int left = 0;
        int right = rotateArray.size() - 1;
        while (left < right)
        {
            //确认子数组是否是类似1,1,2,4,5,..,7的非递减数组,避免错过直接有序情况
            if (rotateArray[left] < rotateArray[right])
                return rotateArray[left];
             
            int mid = left + (right - left) / 2;
            //如果左半数组为有序数组
            if (rotateArray[left] < rotateArray[mid])
                left = mid + 1;  // 左区间不包含最小
            //如果右半数组为有序数组
            else if (rotateArray[mid] < rotateArray[right])
                right = mid; //左区间包含最小的
            //否则，rotateArray[left] == rotateArray[mid] == rotateArray[right]
            else //得一个一个判断
                ++left;
        }
        return rotateArray[left];
    }
};



4、变态跳台阶
https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

class Solution {
public:
    int jumpFloorII(int number) {
        //方法一： 找规律
        //return pow(2, number - 1);
        //return 1 << (number - 1);
        
        //方法二：递归计算
        if(number == 0)
            return 1;
         int count = 0;
        for(int i = 1; i <= number; ++i){
            count += jumpFloorII(number - i);
        }
        return count;
    }
};



5、跳台阶
https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

class Solution {
public:
    int jumpFloor(int number) {
        //找规律，类似于斐波那契数一样
        int first = 1;
        int second = 2;
        while(--number) //使用前置减减，比使用后置减减，少循环一次,
        {
            second = second + first;
            first = second - first;
        }
        return first;
    }
};



6、连续子数组的最大和
https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
            return 0;
        
        int sum = array[0];
        int count = array[0]; //不能设置为零，防止全是负数
        for(size_t i = 1; i < array.size(); ++i)
        {
            if(sum < 0)  //如果小于零的话，直接对后面的影响直接是副作用，更新一下
                sum = array[i];
            else   //否则的话继续加起来
                sum += array[i];
            
            // 记录一下最大的
            if(count < sum)
                count = sum;
        }
        return count;
    }
};


7、整数中1出现的次数（从1到n整数中1出现的次数）
https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。

class Solution {
public:
    // 方法一：
    // 判断一个数字里面有几个1
    int NumberN(int m)
    {
        int num = 0;
        while(m)
        {
            if(m % 10 == 1)
                num++;
            m = m / 10;
        }
        return num;
    }
    
    //遍历每个数且判断数字1个数，加起来
    int NumberOf1Between1AndN_Solution(int n)
    {
        int sum = 0;
        for(int i = 1; i <= n; ++i)
        {
            sum += NumberN(i);
        }
        return sum;
    }
};


8、两个链表的第一个公共结点
https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&tPage=2&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

输入两个链表，找出它们的第一个公共结点

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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int num1 = 0;
        int num2 = 0;
        struct ListNode* cur1 = pHead1;
        struct ListNode* cur2 = pHead2;
        while(cur1)
        {
            num1++;
            cur1 = cur1->next;
        }
        while(cur2)
        {
            num2++;
            cur2 = cur2->next;
        }
        
        cur1 = pHead1;
        cur2 = pHead2;
        if(num1 > num2)
        {
            int ret = num1 - num2;
            while(ret--)
                cur1 = cur1->next;
        }
        if(num1 < num2)
        {
            int ret = num2 - num1;
            while(ret--)
                cur2 = cur2->next;
        }
        while(cur1 && cur2)
        {
            if(cur1 == cur2)
                return cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return NULL;
    }
};



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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        //指向短链表指针先走完，然后指向长链表，指向长链表指针后走完，指向短链表
        //长度相同有公共结点，第一次就遍历到；没有公共结点，走到尾部NULL相遇，返回NULL
        //长度不同有公共结点，第一遍差值就出来了，第二遍一起到公共结点；没有公共，一起到结尾NULL。
        ListNode *cur1 = pHead1;
        ListNode *cur2 = pHead2;
        while(cur1 != cur2)
        {
            cur1 = (cur1 == NULL ? pHead2 : cur1->next);
            cur2 = (cur2 == NULL ? pHead1 : cur2->next);
        }
        return cur1;
    }
};


9、和为S的两个数字
https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        //简单判断一下，可以知道本身是有序的，所以两个数的距离相隔越远乘积越小
        //所以相当于从两头往中间找，第一次找到的的话直接就是满足的
        vector<int> ret;
        int i = 0;
        int j = array.size() - 1;
        int Sum = 0;
        while(i < j)
        {
            Sum = array[i] + array[j];
            if(Sum < sum)
                i++;
            else if(Sum > sum)
                j--;
            else
            {
                ret.push_back(array[i]);
                ret.push_back(array[j]);
                break;
            }
        }
        return ret;
    }
};

10、数组中重复的数字
https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。


class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == NULL || length == 0)
            return 0;
        int HashTable[255]={ 0 };
        for(int i = 0 ; i < length; i++)
        {
            HashTable[numbers[i]]++;
        }
        
        int count = 0;
        for(int i = 0; i < length; i++)
        {
            if(HashTable[numbers[i]] > 1)
            {
                duplication[count++] = numbers[i];
                return true;
            }
        }
        return false;
    }
};