/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 *
 * https://leetcode.com/problems/compare-version-numbers/description/
 *
 * algorithms
 * Medium (30.19%)
 * Likes:    792
 * Dislikes: 1677
 * Total Accepted:    237.1K
 * Total Submissions: 777.2K
 * Testcase Example:  '"1.01"\n"1.001"'
 *
 * Given two version numbers, version1 and version2, compare them.
 *
 *
 *
 *
 * Version numbers consist of one or more revisions joined by a dot '.'. Each
 * revision consists of digits and may contain leading zeros. Every revision
 * contains at least one character. Revisions are 0-indexed from left to right,
 * with the leftmost revision being revision 0, the next revision being
 * revision 1, and so on. For example 2.5.33 and 0.1 are valid version
 * numbers.
 *
 * To compare version numbers, compare their revisions in left-to-right order.
 * Revisions are compared using their integer value ignoring any leading zeros.
 * This means that revisions 1 and 001 are considered equal. If a version
 * number does not specify a revision at an index, then treat the revision as
 * 0. For example, version 1.0 is less than version 1.1 because their revision
 * 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.
 *
 * Return the following:
 *
 *
 * If version1 < version2, return -1.
 * If version1 > version2, return 1.
 * Otherwise, return 0.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: version1 = "1.01", version2 = "1.001"
 * Output: 0
 * Explanation: Ignoring leading zeroes, both "01" and "001" represent the same
 * integer "1".
 *
 *
 * Example 2:
 *
 *
 * Input: version1 = "1.0", version2 = "1.0.0"
 * Output: 0
 * Explanation: version1 does not specify revision 2, which means it is treated
 * as "0".
 *
 *
 * Example 3:
 *
 *
 * Input: version1 = "0.1", version2 = "1.1"
 * Output: -1
 * Explanation: version1's revision 0 is "0", while version2's revision 0 is
 * "1". 0 < 1, so version1 < version2.
 *
 *
 * Example 4:
 *
 *
 * Input: version1 = "1.0.1", version2 = "1"
 * Output: 1
 *
 *
 * Example 5:
 *
 *
 * Input: version1 = "7.5.2.4", version2 = "7.5.3"
 * Output: -1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= version1.length, version2.length <= 500
 * version1 and version2 only contain digits and '.'.
 * version1 and version2 are valid version numbers.
 * All the given revisions in version1 and version2 can be stored in a 32-bit
 * integer.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int compareVersion(string version1, string version2) {
    int i = 0;
    int j = 0;
    for (;;) {
      int v1 = 0;
      int v2 = 0;

      for (; i < version1.size() && version1[i] != '.'; i++) {
        v1 = v1 * 10 + (version1[i] - '0');
      }

      for (; j < version2.size() && version2[j] != '.'; j++) {
        v2 = v2 * 10 + (version2[j] - '0');
      }

      if (v1 > v2) {
        return 1;
      }

      if (v1 < v2) {
        return -1;
      }

      bool end1 = i == version1.size();
      bool end2 = j == version2.size();

      if (end1 && end2) {
        return 0;
      }

      if (!end1) {
        i++;
      }

      if (!end2) {
        j++;
      }
    }

    return 0;
  }
};
// @lc code=end
