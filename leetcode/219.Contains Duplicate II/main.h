//
// Created by vaniot on 18-12-8.
//

/*
 * 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true

示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true

示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false


 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class main {

    //滑动窗口 +c查找表
public :
    //时间复杂度o(n)
    //空间复杂度 o(k)
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> record; //查找表 O(1)级别的查找
        for (int i = 0; i < nums.size(); ++i) {
            if (record.find(nums[i]) != record.end()) { //查找元素是否已经存在
                return true;
            }

            record.insert(nums[i]); //插入元素
            //保持record中最多有k个元素
            if (record.size() == k + 1) {
                record.erase(nums[i-k]);
            }
        }
         return false;
    }
};


#endif //NOTES_MAIN_H
