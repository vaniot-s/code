/*
 * [1] Two Sum
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (42.94%)
 * Total Accepted:    97.4K
 * Total Submissions: 226.9K
 * Testcase Example:  '[2,7,11. Container With Most Water,15]\n9'
 *
 * 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
 * 
 * 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11. Container With Most Water, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            if (m.find(nums[i])==m.end() ) { 
                m[target - nums[i]] = i; 
            }else { 
                result.push_back(m[nums[i]]);
                result.push_back(i);
                break;
            }
        }
        return result; 
    }
};
