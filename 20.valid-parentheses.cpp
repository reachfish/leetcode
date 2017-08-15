/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses
 *
 * algorithms
 * Easy (33.32%)
 * Total Accepted:    222.6K
 * Total Submissions: 667.5K
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 * 
 */

class Solution {
public:
	bool check(stack<char>& stk, char c){
		if(!stk.empty() && stk.top() == c){
			stk.pop();
			return true;
		}

		return false;
	}

    bool isValid(string s) {
		stack<char> stk;        
		for(auto c : s){
			switch(c){
				case '[':
			    case '{':
				case '(':
					stk.push(c);
					break;
				case ')':
					if(!check(stk, '(')) { return false; }
					break;
				case ']':
					if(!check(stk, '[')) { return false; }
					break;
				case '}':
					if(!check(stk, '{')) { return false; }
					break;
				default:
					return false;
			}
		}

		return stk.empty();
    }
};
