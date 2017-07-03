/*
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers
 *
 * Easy (27.61%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '5'
 *
 * 
 * Given a non-negative integer c, your task is to decide whether there're two
 * integers a and b such that a2 + b2 = c.
 * 
 * 
 * Example 1:
 * 
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 3
 * Output: False
 * 
 * 
 */
class Solution {
public:
	bool isSquare(int val){
		int v = sqrt(val);
		return v * v == val;
	}

    bool judgeSquareSum(int c) {
		if(c<0) { return false; }        
		int a = sqrt(c/2);
		int b = a;
		while(a >= 0){
			if(isSquare(c - a * a)) { return true; }
			a--;
		}
		return false;
    }
};
