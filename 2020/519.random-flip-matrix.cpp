/*
 * @lc app=leetcode id=519 lang=cpp
 *
 * [519] Random Flip Matrix
 *
 * https://leetcode.com/problems/random-flip-matrix/description/
 *
 * algorithms
 * Medium (37.95%)
 * Likes:    223
 * Dislikes: 78
 * Total Accepted:    10.6K
 * Total Submissions: 27.9K
 * Testcase Example:  '["Solution", "flip", "flip", "flip", "flip"]\n[[2, 2],
 * [], [], [], []]'
 *
 * You are given the number of rows n_rows and number of columns n_cols of a 2D
 * binary matrix where all values are initially 0. Write a function flip which
 * chooses a 0 value uniformly at random, changes it to 1, and then returns the
 * position [row.id, col.id] of that value. Also, write a function reset which
 * sets all values back to 0. Try to minimize the number of calls to system's
 * Math.random() and optimize the time and space complexity.
 *
 * Note:
 *
 *
 * 1 <= n_rows, n_cols <= 10000
 * 0 <= row.id < n_rows and 0 <= col.id < n_cols
 * flip will not be called when the matrix has no 0 values left.
 * the total number of calls to flip and reset will not exceed 1000.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * ["Solution","flip","flip","flip","flip"]
 * [[2,3],[],[],[],[]]
 * Output: [null,[0,1],[1,2],[1,0],[1,1]]
 *
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ["Solution","flip","flip","reset","flip"]
 * [[1,2],[],[],[],[]]
 * Output: [null,[0,0],[0,1],null,[0,0]]
 *
 *
 * Explanation of Input Syntax:
 *
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has two arguments, n_rows and n_cols. flip and reset
 * have no arguments. Arguments are always wrapped with a list, even if there
 * aren't any.
 *
 */

// @lc code=start
class Solution {
 public:
  Solution(int n_rows, int n_cols) : total_(n_rows * n_cols), cols_(n_cols) {
    reset();
  }

  vector<int> flip() {
    if (zeros_.empty()) {
      return {-1, -1};
    }

    int index = rand() % nzero_;
    int count = 0;
    int num;
    for (auto it = zeros_.begin(); it != zeros_.end(); it++) {
      int last_count = count;
      count += it->count;
      if (index < count) {
        int range_count = it->count;
        int range_index = index - last_count;
        num = it->start + range_index;
        if (range_count == 1) {
          zeros_.erase(it);
        } else if (range_index == 0) {
          it->count--;
          it->start++;
        } else if (range_index == range_count - 1) {
          it->count--;
        } else {
          zeros_.push_back({num + 1, range_count - range_index - 1});
          it->count = range_index;
        }

        break;
      }
    }

    nzero_--;

    return {num / cols_, num % cols_};
  }

  void reset() {
    nzero_ = total_;
    zeros_.clear();
    zeros_.push_back({0, total_});
  }

 private:
  struct Range {
    int start;
    int count;
  };

  const int total_;
  const int cols_;
  int nzero_;
  list<Range> zeros_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
// @lc code=end
