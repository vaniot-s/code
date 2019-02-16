//
// Created by vaniot on 19-2-16.
//
/**
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：

输入: "cbbd"
输出: "bb"


 * */
#ifndef INTRODUCTION_TO_ALGORITHMS_SOLUTION_H
#define INTRODUCTION_TO_ALGORITHMS_SOLUTION_H


class Solution {
public:
    string longestPalindrome(string s) {
        string res,s2,s3;
        for(int i=0;i<s.size();++i)s2+=s[i],s2+="#";
        for(int i=0;i<s2.size();++i){
            int j=i,k=i;
            for(;j>=0&&k<s2.size();--j,++k){
                if(s2[j]!=s2[k])break;
            }
            j++,k--;
            if(k-j+1>s3.size())s3=s2.substr(j,k-j+1);
        }
        for(int i=0;i<s3.size();++i){
            if(s3[i]!='#')res+=s3[i];
        }
        return res;
    }
};


#endif //INTRODUCTION_TO_ALGORITHMS_SOLUTION_H
