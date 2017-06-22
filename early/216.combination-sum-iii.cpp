/*
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii
 *
 * Medium (44.18%)
 * Total Accepted:    66276
 * Total Submissions: 150035
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * 
 * 
 * ⁠Example 1:
 * Input:  k = 3,  n = 7
 * Output: 
 * 
 * [[1,2,4]]
 * 
 * 
 * ⁠Example 2:
 * Input:  k = 3,  n = 9
 * Output: 
 * 
 * [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    void combine(vector<int>& v, int i, int start, int left, vector<vector<int>>& res){
        if(i==v.size()) { 
            if(left == 0) { res.push_back(v); }
            return;
        }
        
        if(left < 0) { return; }
        
        for(int j = start; j<=9; j++) {
            v[i] = j;
            combine(v, i + 1, j + 1, left - j, res);
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(k==0&&n==0) { res.push_back(vector<int>()); }
        if(k<=0||n<=0) { return res; }
        
        vector<int> v(k);
        combine(v, 0, 1, n, res);
        
        return res;
    }
};
