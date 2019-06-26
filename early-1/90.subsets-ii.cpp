/*
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii
 *
 * Medium (35.50%)
 * Total Accepted:    108810
 * Total Submissions: 306499
 * Testcase Example:  '[1,2,2]'
 *
 * 
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets.
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * 
 * For example,
 * If nums = [1,2,2], a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
class Solution {
public:
    void subset(vector<vector<int>> &res, vector<int>& v, const vector<int>& nums, int i){
        if(i>=nums.size()){
            if(i==nums.size()){
                res.push_back(v);
            }
            return;
        }
        
        
        int index = v.size();
        v.push_back(nums[i]);
        subset(res, v, nums, i+1);
        v.erase(v.begin()+index);

        int j = i+1;
        while(j<nums.size()&&nums[j]==nums[i])
            j++;
            
        subset(res, v, nums, j);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int> > res;
        vector<int> v;
        
        subset(res, v, nums, 0);
        
        return res;
    }
};
