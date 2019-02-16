//
// Created by vaniot on 19-2-15.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_MAIN_H
#define INTRODUCTION_TO_ALGORITHMS_MAIN_H

/**
 * 给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"

说明：

    如果 S 中不存这样的子串，则返回空字符串 ""。
    如果 S 中存在这样的子串，我们保证它是唯一的答案。
子串在S中乱序排列
 */
class main {
public:
    string minWindow(string S, string T) {
        if (T.size() > S.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = S.size() + 1;
        unordered_map<char, int> m;

        //统计t中出现的字符数
        for (int i = 0; i < T.size(); ++i) {
            if (m.find(T[i]) != m.end()) ++m[T[i]];
            else m[T[i]] = 1;
        }

        //
        for (int right = 0; right < S.size(); ++right) {
            if (m.find(S[right]) != m.end()) {//每遇到一个t中的字符，则减1
                --m[S[right]];
                if (m[S[right]] >= 0) ++count;//如果那个字符的数量还大于等于0，则说明那个字符原来至少有一个，则count+1
                while (count == T.size()) {//当数目相同时，也就是窗口中能找到t中所有元素了
                    if (right - left + 1 < minLen) {//如果子窗口边界小于最小长度
                        minLen = right - left + 1;//更新最小长度
                        res = S.substr(left, minLen);//取最小长度对应的字符串
                    }
                    if (m.find(S[left]) != m.end()) {//如果m中存在窗口的左边界元素,说明我们移除掉的是一个必须的组成字符
                        ++m[S[left]];//则把对应的数量+1
                        if (m[S[left]] > 0) --count;//如果它的数量大于0，我们的count需要-1。
                    }
                    ++left;//子窗口左移
                }
            }
        }
        return res;
    }
};


#endif //INTRODUCTION_TO_ALGORITHMS_MAIN_H
