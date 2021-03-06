//
// Created by vaniot on 19-1-7.
//
/**
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度

 思路:
   1.排序->O(nlogn)
   2.快排

 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { //依赖排序
        for (int i = 0; i <nums.size() ; ++i) { 
            for (int j = i+1; j <nums.size() ; ++j) {
                if(nums[i]<nums[j]) continue;
                swap(nums[i],nums[j]);
            }
        }
        return nums[nums.size()-k];

    }
};


#endif //NOTES_MAIN_H
