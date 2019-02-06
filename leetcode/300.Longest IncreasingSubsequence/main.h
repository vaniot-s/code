//
// Created by vaniot on 18-12-22.
//
/**
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

说明:

    可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
    你算法的时间复杂度应该为 O(n2) 。

进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
1.子序列
 2.上升
 3.可能存在多个最长上升子序列,但最长的长度只有一个
 暴力解法:O((2^n)*n)
 LIS(i)表示第i个数字为结尾的最长上升子序列的长度,[0...i]的范围内,选择数字nums[i]可以获得最长上升子序列的长度
 LIS(i)=max(1+LIS(j) if nums[i]>nums[j])
 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class main {
public:
    //O(n^2)
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        //memo[i]表示以nums[i]结尾的最长上升子序列的长度,初始化
        vector<int> memo(nums.size(),1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <i ; ++j) {
                if(nums[j]<nums[i]){
                    memo[i]=max(memo[i],1+memo[j]);
                }
            }
        }
        int res=1;
        for (int k = 0; k < nums.size(); ++k) {
            res=max(res,memo[k]);
        }
        return res;
    }
};


#endif //NOTES_MAIN_H
