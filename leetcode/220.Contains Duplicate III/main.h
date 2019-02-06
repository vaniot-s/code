//
// Created by vaniot on 18-12-8.
//
/**
 * 给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。

示例 1:

输入: nums = [1,2,3,1], k = 3, t = 0
输出: true

示例 2:

输入: nums = [1,0,1,1], k = 1, t = 2
输出: true

示例 3:

输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false


 */
#include <set>
#include <vector>
#include <iostream>
using namespace std;

#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class main {
public:
    //时间复杂度为o(nlogn)
    //空间复杂度为o(k)
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long > record; //时间复杂度为logN long long整形溢出
        for (int i = 0; i <nums.size() ; ++i) {
            if (record.lower_bound((long long)nums[i]-(long long)t)!=record.end()&&*record.lower_bound((long long)nums[i]-(long long)t)<=(long long)nums[i]+(long long)t){
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
