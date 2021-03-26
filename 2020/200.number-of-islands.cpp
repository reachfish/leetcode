/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (48.78%)
 * Likes:    7984
 * Dislikes: 241
 * Total Accepted:    998.8K
 * Total Submissions: 2M
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid.front().empty()) {
      return 0;
    }

    int m = grid.size();
    int n = grid.front().size();
    int count = 0;
    struct G {
      int x;
      int y;
    };
    vector<G> que;
    const int kDir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] != '1') {
          continue;
        }

        count++;
        que.clear();
        grid[i][j] = '2';
        que.push_back({i, j});
        while (!que.empty()) {
          auto g = que.back();
          que.pop_back();

          for (const auto& d : kDir) {
            int x = g.x + d[0];
            int y = g.y + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
              grid[x][y] = '2';
              que.push_back({x, y});
            }
          }
        }
      }
    }

    return count;
  }
};
// @lc code=end
