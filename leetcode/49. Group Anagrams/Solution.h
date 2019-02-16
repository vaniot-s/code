//
// Created by vaniot on 19-2-16.
//
/***
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

 */
#ifndef INTRODUCTION_TO_ALGORITHMS_SOLUTION_H
#define INTRODUCTION_TO_ALGORITHMS_SOLUTION_H


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,int> m;
        int i = 0;


        for(auto str:strs){

            string str1 = str;
            sort(str1.begin(),str1.end());

            if (m.count(str1) > 0){
                res[m[str1]].push_back(str);
            }else{
                m[str1] = i++;
                res.push_back(vector<string>{str});
            }

        }
        return res;
    }
};


#endif //INTRODUCTION_TO_ALGORITHMS_SOLUTION_H
