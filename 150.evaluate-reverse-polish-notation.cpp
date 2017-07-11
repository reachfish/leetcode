/*
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation
 *
 * Medium (26.91%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '["18"]'
 *
 * 
 * Evaluate the value of an arithmetic expression in Reverse Polish
 * Notation.
 * 
 * 
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 * 
 * 
 * 
 * Some examples:
 * 
 * ⁠ ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ⁠ ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 * 
 * 
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		stack<int> stk;        
		for(auto token : tokens){
			if(token.size() > 1 || isdigit(token[0])){
				stk.push(atoi(token.c_str()));
				continue;
			}

			int op2 = stk.top();
			stk.pop();

			int op1 = 0;
			if(!stk.empty()){
				op1 = stk.top();
				stk.pop();
			}

			int value = 0;
			switch(token[0]){
				case '+': value = op1 + op2; break;
				case '-': value = op1 - op2; break;
				case '*': value = op1 * op2; break;
				case '/': value = op1 / op2; break;
				default:
						  break;
			}

			stk.push(value);
		}

		return stk.empty() ? 0 : stk.top();
    }
};
