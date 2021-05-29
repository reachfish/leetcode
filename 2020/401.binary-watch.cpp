/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (48.66%)
 * Likes:    753
 * Dislikes: 1326
 * Total Accepted:    96.3K
 * Total Submissions: 197.5K
 * Testcase Example:  '1'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59). Each LED represents a
 * zero or one, with the least significant bit on the right.
 *
 *
 * For example, the below binary watch reads "4:51".
 *
 *
 *
 *
 * Given an integer turnedOn which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent. You may
 * return the answer in any order.
 *
 * The hour must not contain a leading zero.
 *
 *
 * For example, "01:00" is not valid. It should be "1:00".
 *
 *
 * The minute must be consist of two digits and may contain a leading
 * zero.
 *
 *
 * For example, "10:2" is not valid. It should be "10:02".
 *
 *
 *
 * Example 1:
 * Input: turnedOn = 1
 * Output:
 * ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
 * Example 2:
 * Input: turnedOn = 9
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * 0 <= turnedOn <= 10
 *
 *
 */

// @lc code=start
class Solution {
 public:
  Solution() {}

  vector<string> readBinaryWatch(int turnedOn) {
    vector<vector<int>> nums(8);
    for (int i = 0; i < 60; i++) {
      auto n = i;
      int bits = 0;
      while (n) {
        n &= (n - 1);
        bits++;
      }
      nums[bits].push_back(i);
    }

    vector<string> result;
    for (int i = 0; i <= std::min(turnedOn, 4); i++) {
      int j = turnedOn - i;
      if (j > 7) {
        continue;
      }

      for (auto h : nums[i]) {
        if (h > 11) {
          break;
        }
        for (auto m : nums[j]) {
          result.push_back(std::to_string(h) + ":" + (m < 10 ? "0" : "") +
                           std::to_string(m));
        }
      }
    }

    return result;
  }
};
// @lc code=end
