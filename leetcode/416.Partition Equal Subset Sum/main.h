//
// Created by vaniot on 18-12-22.
//
/**
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

    每个数组中的元素不会超过 100
    数组的大小不会超过 200

示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].



示例 2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.
典型背包问题:在n个物品中选出一定的物品,填满sum/2的背包
 F(n,C)考虑将n个物品填满容量为C的背包
 f(i,c)=F(i-1,c)||F(i-1,c-W(i)) 状态转移方程
 时间复杂度 O(n*sum/2)=O(n*sum)
 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class main {
private:
    //递归的解法
    //使用nums[0...index],是否可以完全填充一个容量是sum的背包
//    bool tryPartition(const vector<int> &nums, int index, int sum) {
//        if (sum==0){
//            return  true;
//        }
//        if(sum<0||index<0){
//            return false;
//        }
//       return tryPartition(nums,index-1,sum)||tryPartition(nums,index-1,sum-nums[index]);
//    }

//  记忆化搜索
    //使用nums[0...index],是否可以完全填充一个容量是sum的背包
    //-1表示未计算,0表示不可以填充,1表示可以填充
    vector <vector<int>> memo;

    bool tryPartition(const vector<int> &nums, int index, int sum) {
        if (sum == 0) {
            return true;
        }
        if (sum < 0 || index < 0) {
            return false;
        }

        if (memo[index][sum] != -1) {
            return memo[index][sum] == 1;
        }
        memo[index][sum] = (tryPartition(nums, index - 1, sum) || tryPartition(nums, index - 1, sum - nums[index])) ? 1
                                                                                                                    : 0;
        return memo[index][sum] == 1;
    }

public:
    bool canPartition(vector<int> &nums) {
//        int sum = 0;
//        for (int i = 0; i < nums.size(); ++i) {
//            assert(nums[i] > 0);
//            sum += nums[i];
//        }
//        if (sum % 2 != 0) {
//            return false;
//        }
//        memo = vector < vector<int>(nums.size(), vector<int>(sum / 2 + 1, -1));
//        return tryPartition(nums, nums.size() - 1, sum / 2);


        //动态规划
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            assert(nums[i] > 0);
            sum += nums[i];
        }
        if (sum % 2) {
            return false;
        }
       
        int n=nums.size();
        int c=sum/2;
        vector<bool>memo(c+1,false);
        for (int j = 0; j <=c ; ++j) {
            memo[j]=(nums[0]==j);
        }
        for (int k = 1; k < n; ++k) {
            for (int i = c; i >=nums[k] ; i--) {
                memo[i]=memo[i]||memo[i-nums[k]];
            }
        }
        return memo[c];
    }
};


#endif //NOTES_MAIN_H
