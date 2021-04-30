/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (37.80%)
 * Likes:    2007
 * Dislikes: 58
 * Total Accepted:    102.4K
 * Total Submissions: 270.9K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi]
 * represents the width and the height of an envelope.
 *
 * One envelope can fit into another if and only if both the width and height
 * of one envelope are greater than the other envelope's width and height.
 *
 * Return the maximum number of envelopes you can Russian doll (i.e., put one
 * inside the other).
 *
 * Note: You cannot rotate an envelope.
 *
 *
 * Example 1:
 *
 *
 * Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 *
 *
 * Example 2:
 *
 *
 * Input: envelopes = [[1,1],[1,1],[1,1]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= envelopes.length <= 5000
 * envelopes[i].length == 2
 * 1 <= wi, hi <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    if (envelopes.empty()) {
      return 0;
    }

    struct CompEnvelope {
      bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[0] != b[0]) {
          return a[0] < b[0];
        } else {
          return a[1] < b[1];
        }
      }
    } comp;

    sort(envelopes.begin(), envelopes.end(), comp);
    int max_count = 1;
    vector<int> counter(envelopes.size(), 0);
    counter[0] = 1;
    for (int i = 1; i < envelopes.size(); i++) {
      int max_prev = 0;
      for (int j = 0; j < i; j++) {
        if (envelopes[i][0] == envelopes[j][0]) {
          break;
        }
        if (envelopes[i][1] > envelopes[j][1] && max_prev < counter[j]) {
          max_prev = counter[j];
        }
      }
      counter[i] = max_prev + 1;
      if (counter[i] > max_count) {
        max_count = counter[i];
      }
    }

    return max_count;
  }
};
// @lc code=end
