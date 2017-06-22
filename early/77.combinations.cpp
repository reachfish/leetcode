/*
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations
 *
 * Medium (39.07%)
 * Total Accepted:    114136
 * Total Submissions: 292152
 * Testcase Example:  '4\n2'
 *
 * 
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * 
 * For example,
 * If n = 4 and k = 2, a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
class Solution {
public:
    void combine(int start, int n, int index, vector<int>& v, vector<vector<int>>& res){
        if(index==v.size()) { res.push_back(v); return; }
        
        int left = v.size() - index;
        for(int i=start;i<=n-left+1;i++){
            v[index] = i;
            combine(i+1, n, index+1, v, res);
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        
        if(n<=0||k<=0||k>n) { return res; }
        vector<int> v(k);
        combine(1, n, 0, v, res);
        
        return res;
    }
};
