/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (30.87%)
 * Likes:    9753
 * Dislikes: 1497
 * Total Accepted:    913.7K
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 *
 *
 * Example 3:
 *
 *
 * Input: nums1 = [0,0], nums2 = [0,0]
 * Output: 0.00000
 *
 *
 * Example 4:
 *
 *
 * Input: nums1 = [], nums2 = [1]
 * Output: 1.00000
 *
 *
 * Example 5:
 *
 *
 * Input: nums1 = [2], nums2 = []
 * Output: 2.00000
 *
 *
 *
 * Constraints:
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 *
 * Follow up: The overall run time complexity should be O(log (m+n)).
 */

// @lc code=start
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int total = nums1.size() + nums2.size();
    int v = find(nums1, nums2, total / 2);
    if (total & 1) {
      return v;
    } else {
      int v2 = find(nums1, nums2, total / 2 - 1);
      return double(v + v2) / 2;
    }
  }

  int find(const vector<int>& nums1, const vector<int>& nums2, int k) {
    int s1 = 0, e1 = nums1.size() - 1;
    int s2 = 0, e2 = nums2.size() - 1;
    for (;;) {
      if (s1 > e1) {
        return nums2[s2 + k];
      }

      if (s2 > e2) {
        return nums1[s1 + k];
      }

      if (k == 0) {
        return std::min(nums1[s1], nums2[s2]);
      }

      int hc = (k + 1) / 2;
      int m1 = std::min(e1, s1 + hc - 1);
      int m2 = std::min(e2, s2 + hc - 1);
      int d = 0;
      if (nums1[m1] <= nums2[m2]) {
        d = m1 - s1 + 1;
        s1 = m1 + 1;
      } else {
        d = m2 - s2 + 1;
        s2 = m2 + 1;
      }
      k -= d;
    }

    return 0;
  }
};
// @lc code=end
