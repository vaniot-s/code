/*
 * [7] Reverse Integer
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (28.61%)
 * Total Accepted:    30.6K
 * Total Submissions: 107.1K
 * Testcase Example:  '123'
 *
 * 给定一个 32 位有符号整数，将整数中的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。
 * 
 */
class Solution {
public:
    int reverse(int x) {
         std::string s = std::to_string(x);
		if( s[0] == '-' ){
			std::reverse(s.begin()+1, s.end());
		}else{
			std::reverse(s.begin(), s.end());
		}
		long long res = std::stoll(s);
		
		if( res < -0x7fffffff-1 || res > 0x7fffffff ){
			return 0;
		}else{
			return (int)res;
		}
    }
};
