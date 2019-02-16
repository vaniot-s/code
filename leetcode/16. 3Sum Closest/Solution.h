//
// Created by vaniot on 19-2-16.
//
/***
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
 * 找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 */
#ifndef INTRODUCTION_TO_ALGORITHMS_SOLUTION_H
#define INTRODUCTION_TO_ALGORITHMS_SOLUTION_H


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        if(nums.size() < 3) return res;
        res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            int l = 0, r = nums.size() - 1;
            while(l < r){
                if(l == i || r == i) break;
                res = abs(res - target) < abs(nums[l] + nums[r] - target + nums[i]) ? res : nums[l] + nums[r] + nums[i];
                if(nums[l] + nums[r] == target - nums[i]) return target;
                else if(nums[l] + nums[r] < target - nums[i]) ++l;
                else --r;

            }
        }
        return res;
    }
};


#endif //INTRODUCTION_TO_ALGORITHMS_SOLUTION_H
