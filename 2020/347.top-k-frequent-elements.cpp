/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (62.68%)
 * Likes:    4864
 * Dislikes: 266
 * Total Accepted:    581.5K
 * Total Submissions: 927.8K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 *
 *
 *
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> m;
    for (auto n : nums) {
      m[n]++;
    }

    map<int, vector<int>> counter;
    for (auto it : m) {
      counter[it.second].push_back(it.first);
    }

    vector<int> result;
    result.reserve(k);
    for (auto it = counter.rbegin(); it != counter.rend() && result.size() < k;
         it++) {
      result.insert(result.end(), it->second.begin(), it->second.end());
    }

    return result;
  }
};
// @lc code=end
