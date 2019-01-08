//
// Created by vaniot on 19-1-8.
//
/**
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true

示例 2:

输入: "race a car"
输出: false

 */

#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class Solution {
public:
    class Solution {
    public:
        bool isPalindrome(string s) { //对撞指针
            int i=0;
            int j=s.size()-1;
            while(i<j){
                while(isalnum(s[i])==false&&i<j) i++;
                while(isalnum(s[j])==false&&i<j) j--;
                if(toupper(s[i])!=toupper(s[j])) return false;
                i++;
                j--;
            }
            return true;
        }
    };
};


#endif //NOTES_MAIN_H
