//
// Created by vaniot on 19-1-8.
//
/**
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"

示例 2:

输入: "leetcode"
输出: "leotcede"

 注意:容错 两端交换->对撞指针
 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class Solution {
public:
    string reverseVowels(string s) { //对撞指针
        if (!s.length()) //容错
            return s;
        int l=0;
        int r=s.length()-1;
        while(r<l){
            if(!Vowel(s[l])){
                l++;
            }else if(!Vowel(s[r])){
                r--;
            }else if(Vowel(s[l]) && Vowel(s[r])) {
                swap(s[l], s[r]);
                l ++;
                r --;
            }
        }
        return s;
    }
    bool Vowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};


#endif //NOTES_MAIN_H
