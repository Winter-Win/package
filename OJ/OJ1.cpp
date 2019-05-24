1����������˳��ʹ����λ��ż��ǰ��
https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò���

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //����һ���Ƚ�ż��������һ�������ͬʱ��ԭ����ɾ����������ٽ�������������
        //����ʱ�临�ӶȺͿռ䶼������
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
        //��������������ð�����򣬴�ǰ��������������ڵ���ż����ͽ���λ��
        //���ߴӺ���ǰð�ݣ�����������ڵ�ǰż����ͽ���λ��
        for(size_t i = 0; i < array.size(); ++i)
        {
            //����j > i,���ٱ�������
            for(size_t j = array.size() - 1; j > i; --j)
            {
                if(array[j] % 2 == 1 && array[j - 1] % 2 == 0)
                    swap(array[j], array[j-1]);
            }
        }
    }
};



2����С��K����
https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(), input.end());
        vector<int> ret;
	//��k�����鳤�Ȼ���Ļ���ֱ�Ӿ��Ƿ��ؿգ�Ҳ���԰���ԭ�������û����
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


3����ת�������С����
https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� ����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء� ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;
        //�򵥴ֱ���ֱ������Сֵ���������жϵ�һ����
        sort(rotateArray.begin(), rotateArray.end());
        return rotateArray[0];
    }
};



class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;
        //ֱ������Ļ����ײ��õ��ǿ��ţ�ʱ�临�Ӷ�ƽ�����Ϊ NlogN
        //ʹ�ö��ֲ���˼�룬ʱ�临�Ӷ� logN
        //�������������ֱ�Ӳ�����С���ֵ�
        int left = 0;
        int right = rotateArray.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(rotateArray[mid] > rotateArray[right]) // ˵��һ�����ұ�
                left = mid + 1;
            else if(rotateArray[mid] == rotateArray[right]) //��ʱ��С���ֲ����ж���mid��߻����ұ�,��ʱֻ��һ��һ���� 
                --right;
            else //�������ѯ�ķ�Χ���ֻʣ����������ômid һ����ָ���±꿿ǰ������
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
        //ֱ������Ļ����ײ��õ��ǿ��ţ�ʱ�临�Ӷ�ƽ�����Ϊ NlogN
        //ʹ�ö��ֲ���˼�룬ʱ�临�Ӷ� logN
        //������������ж������Ƿ��ǵ��������
        int left = 0;
        int right = rotateArray.size() - 1;
        while (left < right)
        {
            //ȷ���������Ƿ�������1,1,2,4,5,..,7�ķǵݼ�����,�������ֱ���������
            if (rotateArray[left] < rotateArray[right])
                return rotateArray[left];
             
            int mid = left + (right - left) / 2;
            //����������Ϊ��������
            if (rotateArray[left] < rotateArray[mid])
                left = mid + 1;  // �����䲻������С
            //����Ұ�����Ϊ��������
            else if (rotateArray[mid] < rotateArray[right])
                right = mid; //�����������С��
            //����rotateArray[left] == rotateArray[mid] == rotateArray[right]
            else //��һ��һ���ж�
                ++left;
        }
        return rotateArray[left];
    }
};



4����̬��̨��
https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������

class Solution {
public:
    int jumpFloorII(int number) {
        //����һ�� �ҹ���
        //return pow(2, number - 1);
        //return 1 << (number - 1);
        
        //���������ݹ����
        if(number == 0)
            return 1;
         int count = 0;
        for(int i = 1; i <= number; ++i){
            count += jumpFloorII(number - i);
        }
        return count;
    }
};



5����̨��
https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������

class Solution {
public:
    int jumpFloor(int number) {
        //�ҹ��ɣ�������쳲�������һ��
        int first = 1;
        int second = 2;
        while(--number) //ʹ��ǰ�ü�������ʹ�ú��ü�������ѭ��һ��,
        {
            second = second + first;
            first = second - first;
        }
        return first;
    }
};



6�����������������
https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ����������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý��������,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����һ�����飬��������������������еĺͣ���᲻�ᱻ������ס��(�������ĳ���������1)

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
            return 0;
        
        int sum = array[0];
        int count = array[0]; //��������Ϊ�㣬��ֹȫ�Ǹ���
        for(size_t i = 1; i < array.size(); ++i)
        {
            if(sum < 0)  //���С����Ļ���ֱ�ӶԺ����Ӱ��ֱ���Ǹ����ã�����һ��
                sum = array[i];
            else   //����Ļ�����������
                sum += array[i];
            
            // ��¼һ������
            if(count < sum)
                count = sum;
        }
        return count;
    }
};


7��������1���ֵĴ�������1��n������1���ֵĴ�����
https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����,������������ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�������1 �� n ��1���ֵĴ�������

class Solution {
public:
    // ����һ��
    // �ж�һ�����������м���1
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
    
    //����ÿ�������ж�����1������������
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


8�����������ĵ�һ���������
https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&tPage=2&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

���������������ҳ����ǵĵ�һ���������

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
        //ָ�������ָ�������꣬Ȼ��ָ��������ָ������ָ������ָ꣬�������
        //������ͬ�й�����㣬��һ�ξͱ�������û�й�����㣬�ߵ�β��NULL����������NULL
        //���Ȳ�ͬ�й�����㣬��һ���ֵ�ͳ����ˣ��ڶ���һ�𵽹�����㣻û�й�����һ�𵽽�βNULL��
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


9����ΪS����������
https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ����
����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
�������:
��Ӧÿ�����԰����������������С���������

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        //���ж�һ�£�����֪������������ģ������������ľ������ԽԶ�˻�ԽС
        //�����൱�ڴ���ͷ���м��ң���һ���ҵ��ĵĻ�ֱ�Ӿ��������
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

10���������ظ�������
https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��


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