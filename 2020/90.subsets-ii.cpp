/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (48.61%)
 * Likes:    2200
 * Dislikes: 98
 * Total Accepted:    321.2K
 * Total Submissions: 660.8K
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    static constexpr int N   = 21;
    static constexpr int Low = 10;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int N = 21;
        int count[N];
        for (int i = 0; i < N; i++) { count[i] = 0; }
        for (auto n : nums) { count[n + Low]++; }

        vector<vector<int>> result;
        vector<int> subset;
        dp(result, subset, count, 0);

        return result;
    }

    void dp(vector<vector<int>>& result, vector<int>& subset, int* count, int index) {
        if (index == N) {
            result.push_back(subset);
            return;
        }

        uint32_t sz = subset.size();
        for (uint32_t i = 0; i <= count[index]; i++) {
            subset.resize(sz);

            for (int k = 0; k < i; k++) { subset.push_back(index - Low); }
            dp(result, subset, count, index + 1);
        }
    }
};
// @lc code=end
