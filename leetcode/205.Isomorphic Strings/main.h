//
// Created by vaniot on 19-2-16.
//
/*
 *
 * 给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"
输出: true

示例 2:

输入: s = "foo", t = "bar"
输出: false

示例 3:

输入: s = "paper", t = "title"
输出: true

说明:
你可以假设 s 和 t 具有相同的长度。
映射关系
 * */
#ifndef INTRODUCTION_TO_ALGORITHMS_MAIN_H
#define INTRODUCTION_TO_ALGORITHMS_MAIN_H


class main {
public:
    bool isIsomorphic(string s, string t) {
        /**hash解法***/
        //0 代表没有填写过映射值。
        int fs[128]={0};//保存映射s->t
        int ft[128]={0};//保存映射t->s
        int temp;
        //需要保证t[i]->s[i] 以及s[i]->t[i]都是唯一的
        for(int i=0;i<t.size();i++)
        {
            //尚未映射过，则添加映射
            if(fs[s[i]]==0 && ft[t[i]]==0)
            {
                fs[s[i]]=t[i];
                ft[t[i]]=s[i];
            }
                //都映射过了
            else if(fs[s[i]]!=t[i] || ft[t[i]]!=s[i])
                return false;
        }

        //全部映射成功
        return true;

//           if(s.length()==0)return true;

//     int i=0;

//     while(i<s.length())
//     {

//         if(s.find(s[i])!=t.find(t[i]))
//             return false;

//         i++;

//     }
//    return true;

        //map解法
    }
};


#endif //INTRODUCTION_TO_ALGORITHMS_MAIN_H
