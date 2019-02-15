//
// Created by vaniot on 19-2-5.
//
/**
 * 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

    字母异位词指字母相同，但排列不同的字符串。
    不考虑答案输出的顺序。

示例 1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。

 示例 2:

输入:
s: "abab" p: "ab"

输出:
[0, 1, 2]

解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
 返回子串的起始位置
 */
#ifndef CODE_MAIN_H
#define CODE_MAIN_H
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pos; //用于存储
        if(s.empty() || s.size() < p.size())
            return pos;
        int left = 0;
        int right = p.size() - 1;
        int freqS[26] = { 0 }; //只包含小写字母a~z,数组中保存的是S的子串儿中每个字符出现的次数.对于异构使用表查找,
        int freqP[26] = { 0 };
        for (int i = 0; i < p.size(); i++) {
            freqS[(int)s[i] - (int)'a']++; freqP[(int)p[i] - (int)'a']++;
        }
        while (right < s.size()) {
            int i = 0;
            for ( ; i < 26; i++) {
                if (freqS[i] != freqP[i]) break;
            }
            if(i == 26) pos.push_back(left);
            if(right + 1 == s.size()) return pos;
            freqS[(int)s[left] - (int)'a']--;
            freqS[(int)s[right + 1] - (int)'a']++;
            left++;
            right++;
        }
        return pos;
    }
};
#endif //CODE_MAIN_H
