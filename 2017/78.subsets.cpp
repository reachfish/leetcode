/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets
 *
 * Medium (39.39%)
 * Total Accepted:    161237
 * Total Submissions: 409360
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a set of distinct integers, nums, return all possible subsets.
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * 
 * For example,
 * If nums = [1,2,3], a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [1],
 * ⁠ [2],
 * ⁠ [1,2,3],
 * ⁠ [1,3],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
class Solution {
public:
    void helper(vector<int>& nums, int index, vector<int>& v, vector<vector<int>>& res){
        if(index==nums.size()) { res.push_back(v); return; }
        
        int size = v.size();
        v.push_back(nums[index]);
        helper(nums, index + 1, v, res);
        v.erase(v.begin()+size);
        helper(nums, index + 1, v, res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        helper(nums, 0, v, res);
        return res;
    }
};
