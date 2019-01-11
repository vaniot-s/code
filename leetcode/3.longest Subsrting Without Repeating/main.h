//
// Created by vaniot on 18-12-2.
//

/**
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class main {
    /*
     * 字符集?只有字母?数字+字母?ASCII?
     * 大小写是否敏感*/

    // 滑动窗口 s[i..j] 之后的字母是否产生了重复的字符,子数组,重复性计算=>滑动窗口
    int lengthOfLongestSubstring(tring s){
        int freq[256]={0};
        int l=0;r=-1;//滑动窗口s[l...r];
        int res=0;
        while(l<s.size()){
            if(r+1<s.size()&&fer[s[r+1]]==0){
                freq[s[++r]++];
            }else{
                freq[s[l++]]--;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};


#endif //NOTES_MAIN_H
