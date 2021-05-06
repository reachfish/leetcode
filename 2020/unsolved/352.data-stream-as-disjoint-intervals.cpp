/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 *
 * https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/
 *
 * algorithms
 * Hard (48.86%)
 * Likes:    478
 * Dislikes: 119
 * Total Accepted:    42.7K
 * Total Submissions: 87.4K
 * Testcase Example:
 '["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals"]\n'
 +
  '[[],[1],[],[3],[],[7],[],[2],[],[6],[]]'
 *
 * Given a data stream input of non-negative integers a1, a2, ..., an,
 * summarize the numbers seen so far as a list of disjoint intervals.
 *
 * Implement the SummaryRanges class:
 *
 *
 * SummaryRanges() Initializes the object with an empty stream.
 * void addNum(int val) Adds the integer val to the stream.
 * int[][] getIntervals() Returns a summary of the integers in the stream
 * currently as a list of disjoint intervals [starti, endi].
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals",
 * "addNum", "getIntervals", "addNum", "getIntervals", "addNum",
 * "getIntervals"]
 * [[], [1], [], [3], [], [7], [], [2], [], [6], []]
 * Output
 * [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7,
 * 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]
 *
 * Explanation
 * SummaryRanges summaryRanges = new SummaryRanges();
 * summaryRanges.addNum(1);      // arr = [1]
 * summaryRanges.getIntervals(); // return [[1, 1]]
 * summaryRanges.addNum(3);      // arr = [1, 3]
 * summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
 * summaryRanges.addNum(7);      // arr = [1, 3, 7]
 * summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
 * summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
 * summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
 * summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
 * summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= val <= 10^4
 * At most 3 * 10^4 calls will be made to addNum and getIntervals.
 *
 *
 *
 * Follow up: What if there are lots of merges and the number of disjoint
 * intervals is small compared to the size of the data stream?
 *
 */

// @lc code=start
class SummaryRanges {
 public:
  /** Initialize your data structure here. */
  SummaryRanges() {}

  void addNum(int val) {
    auto it = intervals_.lower_bound(val);

    if (it != intervals_.end()) {
      if (val == it->second + 1) {
        it->second = val;
        auto next = it;
        next++;
        if (next != intervals_.end() && next->first == val + 1) {
          it->second = next->second;
          intervals_.erase(next);
        }
      } else if (val > it->second + 1) {
        auto next = it;
        next++;
        int end_value = val;
        if (next != intervals_.end() && next->first == val + 1) {
          end_value = next->second;
          intervals_.erase(next);
        }
        intervals_[val] = end_value;
      }
    } else if (intervals_.empty()) {
      intervals_[val] = val;
    } else {
      auto prev = it;
      prev--;
      if (val == prev->second + 1) {
        prev->second = val;
      } else if (val > prev->second + 1) {
        intervals_[val] = val;
      }
    }
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> result;
    result.reserve(intervals_.size());
    for (auto it : intervals_) {
      result.push_back({it.first, it.second});
    }

    return result;
  }

 private:
  map<int, int> intervals_;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end
