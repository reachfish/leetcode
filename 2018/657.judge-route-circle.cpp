/*
 * [657] Judge Route Circle
 *
 * https://leetcode.com/problems/judge-route-circle
 *
 * algorithms
 * Easy (69.73%)
 * Total Accepted:    13.3K
 * Total Submissions: 19K
 * Testcase Example:  '"UD"'
 *
 * 
 * Initially, there is a Robot at position (0, 0). Given a sequence of its
 * moves, judge if this robot makes a circle, which means it moves back to the
 * original place. 
 * 
 * 
 * 
 * The move sequence is represented by a string. And each move is represent by
 * a character. The valid robot moves are R (Right), L (Left), U (Up) and D
 * (down). The output should be true or false representing whether the robot
 * makes a circle.
 * 
 * 
 * Example 1:
 * 
 * Input: "UD"
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "LL"
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool judgeCircle(string moves) {
		int left = 0;
		int up = 0;

		for(auto c : moves){
			switch(c){
				case 'L': left++; break;
				case 'R': left--; break;
				case 'U': up++; break;
				case 'D': up--; break;
			}
		}	

		return left == 0 && up == 0;
    }
};
