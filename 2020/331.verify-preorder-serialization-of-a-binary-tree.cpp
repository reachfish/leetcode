/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 *
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (40.92%)
 * Likes:    950
 * Dislikes: 57
 * Total Accepted:    80.1K
 * Total Submissions: 194.4K
 * Testcase Example:  '"9,3,4,#,#,1,#,#,2,#,6,#,#"'
 *
 * One way to serialize a binary tree is to use preorder traversal. When we
 * encounter a non-null node, we record the node's value. If it is a null node,
 * we record using a sentinel value such as '#'.
 *
 * For example, the above binary tree can be serialized to the string
 * "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.
 *
 * Given a string of comma-separated values preorder, return true if it is a
 * correct preorder traversal serialization of a binary tree.
 *
 * It is guaranteed that each comma-separated value in the string must be
 * either an integer or a character '#' representing null pointer.
 *
 * You may assume that the input format is always valid.
 *
 *
 * For example, it could never contain two consecutive commas, such as
 * "1,,3".
 *
 *
 *
 * Example 1:
 * Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Output: true
 * Example 2:
 * Input: preorder = "1,#"
 * Output: false
 * Example 3:
 * Input: preorder = "9,#,#,1"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= preorder.length <= 10^4
 * preoder consist of integers in the range [0, 100] and '#' separated by
 * commas ','.
 *
 *
 *
 * Follow up: Find an algorithm without reconstructing the tree.
 *
 */

// @lc code=start
class Solution {
 public:
  bool isValidSerialization(string preorder) {
    if (preorder.empty()) {
      return false;
    }

    stack<int> sub_count;
    sub_count.push(1);
    int start = 0;
    for (int i = 0; i <= preorder.size(); i++) {
      if (i < preorder.size() && preorder[i] != ',') {
        continue;
      }

      if (sub_count.empty()) {
        return false;
      }

      if (++sub_count.top() == 2) {
        sub_count.pop();
      }

      bool is_null = preorder[i - 1] == '#';
      if (!is_null) {
        sub_count.push(0);
      }
    }

    return sub_count.empty();
  }
};
// @lc code=end
