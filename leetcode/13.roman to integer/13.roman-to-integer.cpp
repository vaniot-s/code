/*
 * [13] Roman to Integer
 *
 * https://leetcode-cn.com/problems/roman-to-integer/description/
 *
 * algorithms
<<<<<<< HEAD
 * Easy (53.81%)
 * Total Accepted:    15.1K
 * Total Submissions: 28.2K
=======
 * Easy (53.67%)
 * Total Accepted:    15.1K
 * Total Submissions: 28.1K
>>>>>>> e3827b6a2a5b307de254e37908996be14c24c249
 * Testcase Example:  '"III"'
 *
 * 罗马数字包含以下七种字符：I， V， X， L，C，D 和 M。
 * 
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V +
 * II 。
 * 
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数
 * 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 * 
 * 
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 
 * 
 * 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 * 
 * 示例 1:
 * 
 * 输入: "III"
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: "IV"
 * 输出: 4
 * 
 * 示例 3:
 * 
 * 输入: "IX"
 * 输出: 9
 * 
 * 示例 4:
 * 
 * 输入: "LVIII"
 * 输出: 58
 * 解释: C = 100, L = 50, XXX = 30, III = 3.
 * 
 * 
 * 示例 5:
 * 
 * 输入: "MCMXCIV"
 * 输出: 1994
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 * 
 */
class Solution {
public:
    int romanToInt(string s) {
        if(s.size()<=0) return 0;
        int count=toInt(s[0]);
        for(int i=0;i<(s.size()-1);i++){
            int now=toInt(s[i]);//当前的数字
            int next=toInt(s[i+1]);//接下来的数字
             if (now <next) {//但前小于接下来的数
                count = count - now+ (next-now);
            }else{
                count += next;
            }
        }
        return count;   
    }

    int toInt(char cha){
        int d=0;
        switch(cha){
        case 'I':  
            d = 1;  
            break;  
        case 'V':  
            d = 5;  
            break;  
        case 'X':  
            d = 10;  
            break;  
        case 'L':  
            d = 50;  
            break;  
        case 'C':  
            d = 100;  
            break;  
        case 'D':  
            d = 500;  
            break;  
        case 'M':  
            d = 1000;  
            break;  
        }
        return d;
    }
};