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