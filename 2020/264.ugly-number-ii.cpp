/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (42.77%)
 * Likes:    2544
 * Dislikes: 158
 * Total Accepted:    204.3K
 * Total Submissions: 474.9K
 * Testcase Example:  '10'
 *
 * Given an integer n, return the n^th ugly number.
 *
 * Ugly number is a positive number whose prime factors only include 2, 3,
 * and/or 5.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 10
 * Output: 12
 * Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first
 * 10 ugly numbers.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 * Explanation: 1 is typically treated as an ugly number.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 1690
 *
 *
 */

// @lc code=start
class Solution {
 public:
  struct Num {
    int value;
    int idx;

    bool operator>(const Num& other) const { return value > other.value; }
  };

  int nthUglyNumber(int n) {
    if (n <= 0) {
      return -1;
    }

    const int kPN = 3;
    const int64_t kPs[kPN] = {2, 3, 5};

    std::priority_queue<Num, std::vector<Num>, std::greater<Num>> que;
    que.push({1, 0});
    for (int i = 1; i < n; i++) {
      auto num = que.top();
      que.pop();
      for (int i = num.idx; i < kPN; i++) {
        int64_t value = num.value * kPs[i];
        int i32 = int(value);
        if (i32 == value) {
          que.push({i32, i});
        }
      }
    }

    return que.top().value;
  }
};
// @lc code=end
