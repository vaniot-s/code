//
// Created by vaniot on 19-2-16.
//
/**
 * 给定一种 pattern(模式) 和一个字符串 str ，判断 str 是否遵循相同的模式。

这里的遵循指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应模式。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true

示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false

示例 3:

输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false

示例 4:

输入: pattern = "abba", str = "dog dog dog dog"
输出: false

说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。

 * **/

#ifndef INTRODUCTION_TO_ALGORITHMS_MAIN_H
#define INTRODUCTION_TO_ALGORITHMS_MAIN_H


class main {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> v(26);
        str += ' ';
        int i = 0, s = 0, e = 0;
        for(;i < pattern.length() && s < str.length()-1;i++, s = e+1){
            e = str.find(" ", s);
            string w = str.substr(s, e-s);
            if(v[pattern[i] - 'a'] != "" && v[pattern[i] - 'a'] != w)
                return 0;
            int pos = find(v.begin(), v.end(), w) - v.begin();
            if(pos != v.end()-v.begin() && pos != pattern[i] - 'a')
                return 0;
            v[pattern[i] - 'a'] = w;
        }
        if(i < pattern.length() || s < str.length()-1)
            return 0;
        return 1;

        // map<char, string> map1;
        // map<string, char> map2;
        // string tmp = "";
        // vector<string> ver;
        // char ch;
        // //分离str中的各个串，放到vector中
        // ch = pattern[0];
        // for(int k = 0; str[k] != '\0'; k++)
        // {
        //     if(str[k] != ' ')
        //         tmp += str[k];
        //     else
        //     {
        //         ver.push_back(tmp);
        //         tmp = "";
        //     }
        // }
        // ver.push_back(tmp);
        // //patter的长度和str中的串的个数不等的话，直接false
        // if(pattern.length() != ver.size())
        //     return false;
        // //把第一个放到map中
        // map1[ch] = ver[0];
        // map2[ver[0]] = ch;
        // //
        // for(int i = 1; pattern[i] != '\0'; i++)
        // {
        //     ch = pattern[i];
        //     tmp = ver[i];
        //     //如果map1中存在ch这个键
        //     if(map1.find(ch) != map1.end())
        //     {
        //         if(map1[ch] != tmp || map2[tmp] != ch)//map1中存在，则map2中也对应存在，否则false
        //             return false;
        //     }
        //     else//如果map1中不存在ch
        //     {
        //         if(map2.find(tmp) != map2.end()) // map2中存在，返回false
        //             return false;
        //         else // 否则，这是一个新键，对应的放到map中
        //         {
        //             map1[ch] = tmp;
        //             map2[tmp] = ch;
        //         }
        //     }
        // }
        // return true;
    }
};


#endif //INTRODUCTION_TO_ALGORITHMS_MAIN_H
