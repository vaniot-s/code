//
// Created by vaniot on 19-2-16.
//
/***
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]


 */
#ifndef INTRODUCTION_TO_ALGORITHMS_SOLUTION_H
#define INTRODUCTION_TO_ALGORITHMS_SOLUTION_H


class solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //排序
        set<vector<int>> S;
        for(int i = 0; i < nums.size(); ++i){ //2 sum
            vector<int> tmp;
            int l = 0, r = nums.size() - 1;
            while(l < r){
                if(l == i) {break;}
                if(r == i) {break;}
                if(nums[l] + nums[r] + nums[i] == 0){
                    vector<int> tmp = {nums[l],nums[i],nums[r]};
                    S.insert(tmp); ++l; --r;
                }else if(nums[l] + nums[r] + nums[i] < 0){
                    ++l;
                }else --r;
            }
        }
        vector<vector<int>> res(S.begin(), S.end());
        return res;
    }
};


#endif //INTRODUCTION_TO_ALGORITHMS_SOLUTION_H
