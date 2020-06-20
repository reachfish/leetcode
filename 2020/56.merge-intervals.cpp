/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (38.87%)
 * Likes:    4061
 * Dislikes: 282
 * Total Accepted:    584.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }

        struct comp {
            bool operator()(const vector<int>& lh, const vector<int>& rh) const {
                if (lh[0] != rh[0]) {
                    return lh[0] < rh[0];
                } else {
                    return lh[1] < rh[1];
                }
            }
        };

        sort(intervals.begin(), intervals.end(), comp());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (const auto& range : intervals) {
            auto& last = result.back();
            if (range[0] > last[1]) {
                result.push_back(range);
            } else if (range[1] > last[1]) {
                last[1] = range[1];
            }
        }

        return result;
    }
};
// @lc code=end
