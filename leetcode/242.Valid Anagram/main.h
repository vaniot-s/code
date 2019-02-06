//
// Created by vaniot on 19-2-6.
//
/***
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true

示例 2:

输入: s = "rat", t = "car"
输出: false

说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

 */
#ifndef CODE_MAIN_H
#define CODE_MAIN_H
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i ++) {
            map[s[i]] ++;
        }
        for (int i = 0; i < t.size(); i ++) {
            //没有相同的元素
            if (map.find(t[i]) == map.end()) return false;
            map[t[i]] --;
            if (map[t[i]] < 0) return false;
        }
        return true;
    }
};
#endif //CODE_MAIN_H
