//
// Created by vaniot on 18-12-20.
//
/**
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。

示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。

说明: 你可以假设 n 不小于 2 且不大于 58。
暴力解法：回溯遍历将一个数做分割的所有可能性O(2^n)

 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class main {
    /**记忆化搜索**/
//private:
//    vector<int>memo;
//    int max3(int a,int b,int c){
//        return max(a,max(b,c));
//    }
//    /**
//     * 将n进行分割至少分割两部分，可以获得最大的面积
//     * @param n
//     * @return
//     */
//    int breakInteger(int n){
//        if(n==1){
//            return 1;
//        }
//        if(memo[n]!=-1){
//            return  memo[n];
//        }
//        int res=-1;
//        for (int i = 1; i <=n-1 ; i++) {
//            res=max3(res,i*(n-i),i*breakInteger(n-i));
//        }
//        memo[n]=res;
//        return res;
//
//    }
//public:
//    int integerBreak(int n) {
//        assert(n>=2);
//        memo=vector<int>(n+1,-1);
//        return breakInteger(n);
//    }

    /**动态规划**/
private:
    vector<int>memo;
    int max3(int a,int b,int c){
        return max(a,max(b,c));
    }
    /*
     * @param n
     * @return
     */

public:
    int integerBreak(int n) {
        assert(n>=2);

        //  memo[i]表示将数字i分割至少分割两部分，可以获得最大的面积
        memo=vector<int>(n+1,-1);
       memo[1]=1;
       for(int i=2;i<=n;i++){
           //求memo[j]
           for(int j=1;j<=i-1;j++){
              memo[i]=max3(memo[i], j*(i-j),j*memo[i-j]);
           }
       }
       return memo[n];
    }
};


#endif //NOTES_MAIN_H
