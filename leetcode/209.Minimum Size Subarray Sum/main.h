//
// Created by vaniot on 18-12-2.
//

#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H

/*
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

示例:

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
 * */
#include <vector>

using namespace std;

class main {

    // 1.暴力解法: 遍历所有的连续子数组[i...j] 计算其和SUm验证SUM>=s 时间复杂度为O(n^3) 优化暴力解法o(n^2) 包含大量的重复计算

    //滑动窗口 nums[i...j] 计算 nums[i...j+1]
public :
    int minSubArrayLen(int s, vector<int> &nums) { //时间复杂度O(n) 空间复杂度O(1),连续的
        int l = 0, r = -1; //索引,滑动窗口nums[l...r],变化为l到r间
        int sum = 0; //和
        int res = nums.size() + 1; //当前最小的长度,初始值为最大,之后比较
        while (l < nums.size()) { //滑动的条件,左边界小于数组右边界,减少重复性计算
            if (r + 1 < nums.size() && sum < s) { //和小于给定的值,r小于右边界,才可拓展
                sum += nums[++r]; //sum
            } else {
                sum -= nums[l++]; //SUM>s
            }
            if (sum >= s) { //可行子数组
                res = min(res, r - l + 1);
            }
        }
        if (res == nums.size() + 1) { //未找到
            return 0;
        }
        return res;

    }
};


#endif //NOTES_MAIN_H
