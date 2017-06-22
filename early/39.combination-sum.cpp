/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum
 *
 * Medium (37.76%)
 * Total Accepted:    156593
 * Total Submissions: 414664
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 
 * Given a set of candidate numbers (C) (without duplicates) and a target
 * number (T), find all unique combinations in C where the candidate numbers
 * sums to T. 
 * 
 * 
 * The same repeated number may be chosen from C unlimited number of times.
 * 
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * 
 * [
 * ⁠ [7],
 * ⁠ [2, 2, 3]
 * ]
 * 
 * 
 */
class Solution {
public:
    void combine(vector<int>& candidates,int i, int left, vector<int>& v, vector<vector<int>>& res){
        if(left <= 0 || i>=candidates.size()) {
            if(left == 0) { res.push_back(v); }
            return;
        }    
        
        int size = v.size();
        int val = candidates[i];
        
        for(int k=0;left - k * val >= 0; k++){
            for(int j=0;j<k;j++) {
                v.push_back(val);
            }
            
            combine(candidates, i + 1, left - k*val, v, res);
            
            v.erase(v.begin() + size, v.end());
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        
        vector<int> v;
        
        combine(candidates, 0, target, v, res);
        return res;
    }
};
