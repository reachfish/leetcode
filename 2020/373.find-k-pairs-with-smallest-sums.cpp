/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (38.09%)
 * Likes:    1937
 * Dislikes: 130
 * Total Accepted:    127.8K
 * Total Submissions: 335K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k.
 *
 * Define a pair (u, v) which consists of one element from the first array and
 * one element from the second array.
 *
 * Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest
 * sums.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * Output: [[1,2],[1,4],[1,6]]
 * Explanation: The first 3 pairs are returned from the sequence:
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * Output: [[1,1],[1,1]]
 * Explanation: The first 2 pairs are returned from the sequence:
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 *
 *
 * Example 3:
 *
 *
 * Input: nums1 = [1,2], nums2 = [3], k = 3
 * Output: [[1,3],[2,3]]
 * Explanation: All possible pairs are returned from the sequence:
 * [1,3],[2,3]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length <= 10^4
 * -10^9 <= nums1[i], nums2[i] <= 10^9
 * nums1 and nums2 both are sorted in ascending order.
 * 1 <= k <= 1000
 *
 *
 */

// @lc code=start
class Solution {
 public:
  struct Pair {
    int i;
    int j;
    int sum;

    bool operator>(const Pair& other) const { return sum > other.sum; }
  };

  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    if (nums1.empty() || nums2.empty() || k <= 0) {
      return {};
    }

    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> que;
    for (int i = 0; i < nums1.size(); i++) {
      que.push({i, 0, nums1[i] + nums2[0]});
    }

    vector<vector<int>> result;
    result.reserve(std::min<int>(k, nums1.size() * nums2.size()));
    while (!que.empty() && result.size() < k) {
      auto t = que.top();
      que.pop();
      result.push_back({nums1[t.i], nums2[t.j]});
      auto nj = t.j + 1;
      if (nj < nums2.size()) {
        que.push({t.i, nj, nums1[t.i] + nums2[nj]});
      }
    }

    return result;
  }
};
// @lc code=end
