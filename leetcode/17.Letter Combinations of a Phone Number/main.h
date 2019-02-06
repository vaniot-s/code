//
// Created by vaniot on 18-12-15.
//
/**
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

 //树形问题->递归
 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class main {
public:
    vector <string> letterCombinations(string digits) {
        res.clear();
        if (digits==""){
            return res;
        }
        findCobination(s,0,"");
        return res;
    }

private:
    const string letterMap[10] = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
    }
    vector<string> res;
    /**
     *寻找digits[index]匹配的字母,获取digits[0...index-1]翻译得到的一个字母
     * @param digits
     * @param index
     * @param s digits[0...index-1]翻译得到的一个字母字符串
     */
    void findCobination(const string &digits, int index, const string &s) {
        if (index == digits.size()) {
            //保存s
            res.push_back(s);
            return ;
        }
        char c = digits[index];
        assert(c >= '0' && c <= '9' && c != '1');
        string letters = letterMap[c - '0'];
        for (int i = 0; i < letters.size(); ++i) {
            findCobination(digits, index + 1, s + letters[i]);
        }
        return;
    }
};


#endif //NOTES_MAIN_H
寻找