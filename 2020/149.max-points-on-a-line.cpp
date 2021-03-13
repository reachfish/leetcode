/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (17.30%)
 * Likes:    30
 * Dislikes: 12
 * Total Accepted:    173.5K
 * Total Submissions: 994.4K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * Given an array of points where points[i] = [xi, yi] represents a point on
 * the X-Y plane, return the maximum number of points that lie on the same
 * straight line.
 *
 *
 * Example 1:
 *
 *
 * Input: points = [[1,1],[2,2],[3,3]]
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= points.length <= 300
 * points[i].length == 2
 * -10^4 <= xi, yi <= 10^4
 * All the points are unique.
 *
 *
 */

// @lc code=start
//(a/b)
struct Factor {
  int a;
  int b;

  bool operator<(const Factor& other) const {
    if (is_max()) {
      return false;
    }

    if (other.is_max()) {
      return true;
    }

    return a * other.b < b * other.a;
  }

  bool operator==(const Factor& other) const {
    if (is_max()) {
      return other.is_max();
    }

    if (other.is_max()) {
      return false;
    }

    return a * other.b == b * other.a;
  }

  bool is_max() const { return b == 0; }
};

struct Line {
  Factor k;
  Factor d;

  bool operator<(const Line& other) const {
    if (!(k == other.k)) {
      return k < other.k;
    }
    if (!(d == other.d)) {
      return d < other.d;
    }
    return false;
  }

  bool operator==(const Line& other) const {
    return k == other.k && d == other.d;
  }
};

struct Stat {
  int index;
  int count;
};

ostream& operator<<(ostream& os, const Factor& f) {
  os << f.a << "/" << f.b;
  return os;
}

ostream& operator<<(ostream& os, const Line& ln) {
  os << "(" << ln.k << ", " << ln.d << ")";
  return os;
}

class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    if (points.size() == 0) {
      return 0;
    }

    map<Line, Stat> stats;
    for (int i = 0; i < points.size(); i++) {
      const auto& p2 = points[i];
      int x2 = points[i][0];
      int y2 = points[i][1];
      for (int j = i + 1; j < points.size(); j++) {
        int x1 = points[j][0];
        int y1 = points[j][1];
        int dy = y2 - y1;
        int dx = x2 - x1;
        if (dx < 0) {
          dx = -dx;
          dy = -dy;
        }

        Factor k{dy, dx};
        Factor b = k.is_max() ? Factor{x1, 1} : Factor{y2 * dx - x2 * dy, dx};
        Line ln{k, b};
        auto it = stats.find(ln);
        if (it != stats.end() && it->second.index != i) {
          continue;
        }

        stats[ln].index = i;
        stats[ln].count++;
      }
    }

    int mx = 0;
    for (const auto& it : stats) {
      // std::cout << it.first << "=" << it.second.count << ", ";
      mx = std::max(mx, it.second.count);
    }

    return mx + 1;
  }
};

// @lc code=end
