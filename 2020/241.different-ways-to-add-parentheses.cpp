/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (57.08%)
 * Likes:    2144
 * Dislikes: 116
 * Total Accepted:    121K
 * Total Submissions: 210K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string expression of numbers and operators, return all possible
 * results from computing all the different possible ways to group numbers and
 * operators. You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: expression = "2-1-1"
 * Output: [0,2]
 * Explanation:
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 *
 *
 * Example 2:
 *
 *
 * Input: expression = "2*3-4*5"
 * Output: [-34,-14,-10,-10,10]
 * Explanation:
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= expression.length <= 20
 * expression consists of digits and the operator '+', '-', and '*'.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  static const int kAdd = 1;
  static const int kMinus = 2;
  static const int kMul = 3;

  vector<int> diffWaysToCompute(string expression) {
    std::vector<int> operators;
    int value = 0;
    for (auto c : expression) {
      int op = -1;
      switch (c) {
        case '+':
          op = kAdd;
          break;
        case '-':
          op = kMinus;
          break;
        case '*':
          op = kMul;
          break;
        default:
          break;
      }

      if (op != -1) {
        operators.push_back(value);
        operators.push_back(op);
        value = 0;
      } else {
        value *= 10;
        value += c - '0';
      }
    }

    operators.push_back(value);

    return helper(operators, 0);
  }

  vector<int> helper(const std::vector<int>& operators, int i) {
    if (i + 1 == operators.size()) {
      return {operators.back()};
    }

    if (i >= operators.size()) {
      return {};
    }

    vector<int> results = helper(operators, i + 2);
    const int v1 = operators[i];
    const int op1 = operators[i + 1];
    for (auto& num : results) {
      num = operate(v1, op1, num);
    }

    if (i + 4 < operators.size()) {
      const int v12 = operate(v1, op1, operators[i + 2]);
      const int op2 = operators[i + 3];
      for (auto num : helper(operators, i + 4)) {
        results.push_back(operate(v12, op2, num));
      }
    }

    return results;
  }

  int operate(int v1, int op, int v2) {
    switch (op) {
      case kAdd:
        return v1 + v2;
      case kMinus:
        return v1 - v2;
      case kMul:
        return v1 * v2;
    }

    return 0;
  }
};
// @lc code=end
