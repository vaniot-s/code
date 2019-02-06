//
// Created by vaniot on 19-2-6.
//
/**
 * 编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

示例:

输入: 19
输出: true
解释:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
 */
#ifndef CODE_MAIN_H
#define CODE_MAIN_H
class Solution {
public:
    //记录已经计算的结果中是否已经出现,若出现是死循环
    bool isHappy(int n) {
        set<int> resultSet; //结果集
        int res=0;
        res=result(n);
        while(res!=1 ){//继续循环数
            res=result(res);
            if ( resultSet.count(res)) break;//出现了死循环
            else resultSet.insert(res); //
        }
        return res == 1;
    }

private:
    int result(int n){
        int res=0;
        while(n){
            res+=(n%10)*(n%10);
            n/=10;
        }
        return res;
    }
    // public:
    // bool isHappy(int n) {
    //     set<int> s;
    //     while (n != 1) {
    //         int t = 0;
    //         while (n) {
    //             t += (n % 10) * (n % 10);
    //             n /= 10;
    //         }
    //         n = t;
    //         if (s.count(n)) break;
    //         else s.insert(n);
    //     }
    //     return n == 1;
    // }
};
#endif //CODE_MAIN_H
