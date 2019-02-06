//
// Created by vaniot on 18-12-22.
//
/**
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。

示例 2:

输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
暴力解法:检查所有的房子的组合,对于一个组合,检查是否有相邻的房子,如果没有,记录其价值,找到最大值O(2^你)*n)
 求最大的组合->回溯
 递归->递归树->记忆化搜索->动态规划
状态:定义函数功能
 状态转移:定义转移的实现方式
 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class main {
private:
    /**
     * 考虑抢劫nums[index...num.size())范围中的所有的房子,递归的实现方案
     * @param nums
     * @param index
     * @return
     */
//    int tryRob(vector<int> &nums, int index) {
//        if (index>=nums.size()){ //递归的终止条件
//            return 0;
//        }
//        int res=0;
//        for (int i = index; i <nums.size() ; ++i) {
//            res=max(nums[i]+tryRob(nums,i+2));
//        }
//        return res;
//    }

    //记忆化搜索
    //memo[i]表示考虑抢劫nums[I...N)所能获得的最大的收益
//    vector<int> memo;
//
//    int tryRob(vector<int> &nums, int index) {
//        if (index >= nums.size()) { //递归的终止条件
//            return 0;
//        }
//        if (memo[index] != -1) {
//            return memo[index];
//        }
//        int res = 0;
//        for (int i = index; i < nums.size(); ++i) {
//            res = max(res, nums[i] + tryRob(nums, i + 2));
//        }
//        memo[index] = res;
//        return res;
//    }


public:
    int rob(vector<int> &nums) {
        // return tryRob(nums, 0); //状态:考虑盗取

        //记忆化搜索
//        memo = vector<int>(nums.size(), -1);
//        return tryRob(nums, 0);

      //动态规划:自底向上的实现思路o(n^2)
      int n=nums.size();
      if(n==0){
          return 0;
      }
        //memo[i]表示考虑抢劫nums[I...N)所能获得的最大的收益
      vector<int> memo(n,-1);
      //基础子问题n-1到n-1的元素
      memo[n-1]=nums[n-1];
        for (int i = n-2; i >=0 ; i--) {
            //memmo[i]
            for (int j = i; j < n; ++j) {
                memo[i]=max(memo[i],nums[j]+(j+2<n?memo[j+2]:0));//状态转移方程
            }
        }
        return memo[0];
    }
};


#endif //NOTES_MAIN_H
