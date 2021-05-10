/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 *
 * https://leetcode.com/problems/mini-parser/description/
 *
 * algorithms
 * Medium (34.70%)
 * Likes:    293
 * Dislikes: 975
 * Total Accepted:    42.9K
 * Total Submissions: 123.6K
 * Testcase Example:  '"324"'
 *
 * Given a string s represents the serialization of a nested list, implement a
 * parser to deserialize it and return the deserialized NestedInteger.
 *
 * Each element is either an integer or a list whose elements may also be
 * integers or other lists.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "324"
 * Output: 324
 * Explanation: You should return a NestedInteger object which contains a
 * single integer 324.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "[123,[456,[789]]]"
 * Output: [123,[456,[789]]]
 * Explanation: Return a NestedInteger object containing a nested list with 2
 * elements:
 * 1. An integer containing value 123.
 * 2. A nested list containing two elements:
 * ⁠   i.  An integer containing value 456.
 * ⁠   ii. A nested list with one element:
 * ⁠        a. An integer containing value 789
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * s consists of digits, square brackets "[]", negative sign '-', and commas
 * ','.
 * s is the serialization of valid NestedInteger.
 *
 *
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it. void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
 public:
  NestedInteger deserialize(string s) {
    stack<NestedInteger> stk;
    int value = 0;
    bool has_value = false;
    bool is_neg = false;

    stk.push({});
    for (auto c : s) {
      switch (c) {
        case '[': {
          stk.push({});
          break;
        }

        case ']':
        case ',': {
          if (has_value) {
            stk.top().add({value});
          }
          if (c == ']') {
            auto t = stk.top();
            stk.pop();
            stk.top().add(t);
          }
          value = 0;
          has_value = false;
          is_neg = false;
          break;
        }

        case '-': {
          is_neg = true;
          break;
        }

        default: {
          has_value = true;
          value *= 10;
          value += (is_neg ? -1 : 1) * (c - '0');
        }
      }
    }

    if (has_value) {
      stk.top().add({value});
    }

    return stk.top().getList()[0];
  }
};
// @lc code=end
