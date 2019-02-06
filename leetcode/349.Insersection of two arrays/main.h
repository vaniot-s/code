//
// Created by vaniot on 19-2-5.
//
/**
 * 给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]

示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]

说明:

    输出结果中的每个元素一定是唯一的。
    我们可以不考虑输出结果的顺序。


 */

#ifndef CODE_MAIN_H
#define CODE_MAIN_H
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { //o(n)
        set<int> record; //将记录存入record中
        for(int i=0;i<nums1.size();i++){
            record.insert(nums1[i]);
        }
        set<int> resultSet; //结果集
        for (int j = 0; j <nums2.size() ; ++j) {
            if (record.find(nums2[j])!=record.end()){
                resultSet.insert(nums2[j]);
            }
        }

//        vector<int> resultVector; //返回
//        for (set<int>::iterator iter=resultSet.begin();iter!=resultSet.end();iter++)
//            resultVector.push_back(*iter);
//        return resultVector;
         return vector<int>(resultSet.begin(),resultSet.end())
    }
};
#endif //CODE_MAIN_H
