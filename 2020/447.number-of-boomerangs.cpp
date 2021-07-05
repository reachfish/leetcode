/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Medium (52.55%)
 * Likes:    484
 * Dislikes: 779
 * Total Accepted:    74.8K
 * Total Submissions: 141.9K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * You are given n points in the plane that are all distinct, where points[i] =
 * [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance
 * between i and j equals the distance between i and k (the order of the tuple
 * matters).
 *
 * Return the number of boomerangs.
 *
 *
 * Example 1:
 *
 *
 * Input: points = [[0,0],[1,0],[2,0]]
 * Output: 2
 * Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and
 * [[1,0],[2,0],[0,0]].
 *
 *
 * Example 2:
 *
 *
 * Input: points = [[1,1],[2,2],[3,3]]
 * Output: 2
 *
 *
 * Example 3:
 *
 *
 * Input: points = [[1,1]]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * n == points.length
 * 1 <= n <= 500
 * points[i].length == 2
 * -10^4 <= xi, yi <= 10^4
 * All the points are unique.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int count = 0;
    map<int, int> d;
    for (int i = 0; i < points.size(); i++) {
      for (int j = 0; j < points.size(); j++) {
        if (i == j) {
          continue;
        }

        int x = points[i][0] - points[j][0];
        int y = points[i][1] - points[j][1];
        int dist = x * x + y * y;
        d[dist]++;
      }
      for (const auto& it : d) {
        int c = it.second;
        count += c * (c - 1);
      }
      d.clear();
    }

    return count;
  }
};
// @lc code=end
