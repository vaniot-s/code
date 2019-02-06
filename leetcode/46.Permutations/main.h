//
// Created by vaniot on 18-12-16.
//
/**
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]


 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class main {
private:
    vector <vector<int>> res;
    vector<bool> used;

    /**
     * p中保存一个有index个元素的排列
     * 向这个排列的尾末添加第index+1个元素,获得一个有index+1元素的排列
     * @param nums
     * @return
     */
    void generatePermutation(const vector<int>& nums, int index, vector<int>& p) {
        if (index == nums.size()) {
            res.push_back(p);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) { //是否使用了nums[i]
                p.push_back(nums[i]);
                used[i] = true;
                generatePermutation(nums, index + 1, p);
                p.pop_back(); //退掉元素
                used[i] = false;
            }

        }
        return;
    }

public:
    vector <vector<int>> permute(vector<int> &nums) {
        res.clear();
        if (nums.size() == 0) {
            return res;
        }
        used = vector<bool>(nums.size(), false);
        vector<int> p;

        generatePermutation(nums, 0, p);
        return res;
    }


};


#endif //NOTES_MAIN_H
