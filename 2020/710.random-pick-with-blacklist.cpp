/*
 * @lc app=leetcode id=710 lang=cpp
 *
 * [710] Random Pick with Blacklist
 *
 * https://leetcode.com/problems/random-pick-with-blacklist/description/
 *
 * algorithms
 * Hard (33.14%)
 * Likes:    435
 * Dislikes: 77
 * Total Accepted:    19K
 * Total Submissions: 57.4K
 * Testcase Example:  '["Solution", "pick", "pick", "pick"]\n[[1, []], [], [],
 * []]'
 *
 * Given a blacklist blacklist containing unique integers from [0, n), write a
 * function to return a uniform random integer from [0, n) which is NOT in
 * blacklist.
 *
 * Optimize it such that it minimizes the call to system’s Math.random().
 *
 * Note:
 *
 *
 * 1 <= n <= 1000000000
 * 0 <= blacklist.length < min(100000, n)
 * [0, n) does NOT include n. See interval notation.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * ["Solution","pick","pick","pick"]
 * [[1,[]],[],[],[]]
 * Output: [null,0,0,0]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ["Solution","pick","pick","pick"]
 * [[2,[]],[],[],[]]
 * Output: [null,1,1,1]
 *
 *
 * Example 3:
 *
 *
 * Input:
 * ["Solution","pick","pick","pick"]
 * [[3,[1]],[],[],[]]
 * Output: [null,0,0,2]
 *
 *
 * Example 4:
 *
 *
 * Input:
 * ["Solution","pick","pick","pick"]
 * [[4,[2]],[],[],[]]
 * Output: [null,1,3,1]
 *
 *
 * Explanation of Input Syntax:
 *
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has two arguments, n and the blacklist blacklist.
 * pick has no arguments. Arguments are always wrapped with a list, even if
 * there aren't any.
 *
 */

// @lc code=start
class Solution {
 public:
  Solution(int n, vector<int>& blacklist) {
    sort(blacklist.begin(), blacklist.end());

    int index = 0;
    for (int i = 0; i <= blacklist.size(); i++) {
      int start;
      int end;
      if (i != blacklist.size()) {
        start = i ? blacklist[i - 1] + 1 : 0;
        end = blacklist[i] - 1;
      } else {
        start = blacklist.empty() ? 0 : blacklist.back() + 1;
        end = n - 1;
      }
      if (start <= end) {
        whitelist_[index] = start;
        index += end - start + 1;
      }
    }

    n_ = index;
  }

  int pick() {
    int index = rand() % n_;
    auto it = whitelist_.upper_bound(index);
    --it;
    return it->second + index - it->first;
  }

 private:
  int n_;
  map<int, int> whitelist_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end
