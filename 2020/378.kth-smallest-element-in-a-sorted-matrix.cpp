/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (56.59%)
 * Likes:    3585
 * Dislikes: 183
 * Total Accepted:    258.2K
 * Total Submissions: 455.7K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given an n x n matrix where each of the rows and columns are sorted in
 * ascending order, return the k^th smallest element in the matrix.
 *
 * Note that it is the k^th smallest element in the sorted order, not the k^th
 * distinct element.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 * Output: 13
 * Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and
 * the 8^th smallest number is 13
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[-5]], k = 1
 * Output: -5
 *
 *
 *
 * Constraints:
 *
 *
 * n == matrix.length
 * n == matrix[i].length
 * 1 <= n <= 300
 * -10^9 <= matrix[i][j] <= 10^9
 * All the rows and columns of matrix are guaranteed to be sorted in
 * non-decreasing order.
 * 1 <= k <= n^2
 *
 *
 */

// @lc code=start
class Solution {
 public:
  struct Elem {
    int i;
    int j;
    int value;

    bool operator>(const Elem& other) const { return value > other.value; }
  };

  int kthSmallest(vector<vector<int>>& matrix, int k) {
    std::priority_queue<Elem, std::vector<Elem>, std::greater<Elem>> que;
    int n = matrix.size();
    for (int i = 0; i < n && que.size() < k; i++) {
      que.push({i, 0, matrix[i][0]});
    }

    for (int i = 1; i < k; i++) {
      auto t = que.top();
      que.pop();
      auto nj = t.j + 1;
      if (nj < n) {
        que.push({t.i, nj, matrix[t.i][nj]});
      }
    }

    return que.top().value;
  }
};
// @lc code=end
