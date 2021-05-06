/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (38.04%)
 * Likes:    2113
 * Dislikes: 173
 * Total Accepted:    203.1K
 * Total Submissions: 531.1K
 * Testcase Example:  '"1 + 1"'
 *
 * Given a string s representing an expression, implement a basic calculator to
 * evaluate it.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "1 + 1"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: s = " 2-1 + 2 "
 * Output: 3
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consists of digits, '+', '-', '(', ')', and ' '.
 * s represents a valid expression.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  enum Type { ADD, SUB, VALUE };
  struct Elem {
    Type type;
    int value;
  };

  int calculate(string s) {
    stack<Elem> stk;
    int value = 0;
    for (auto c : s) {
      if (c == '+') {
        stk.push({ADD, 0});
      } else if (c == '-') {
        stk.push({SUB, 0});
      }
    }

    return stk.empty() ? 0 : stk.top().value;
  }
};
// @lc code=end
