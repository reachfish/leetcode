/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii
 *
 * Medium (32.99%)
 * Total Accepted:    112733
 * Total Submissions: 341734
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 
 * Given a collection of candidate numbers (C) and a target number (T), find
 * all unique combinations in C where the candidate numbers sums to T.
 * 
 * 
 * Each number in C may only be used once in the combination.
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
 * A solution set is: 
 * 
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 */
class Solution {
public:
    void Find(int target, const vector<pair<int, int> > &cans, int index, vector<int> &vec, int sum, vector<vector<int> > &res)
    {
        if(sum==target){
            res.push_back(vec);
            return;
        }

        if(index >= cans.size()||sum > target){
            return;
        }
        
        int val = cans[index].first;
        int count = cans[index].second;
        
        for(int i=0;i<=count;i++){
            for(int k=1;k<=i;k++) {
                vec.push_back(val);
            }
            
            Find(target, cans, index + 1, vec, sum + val * i, res);
            
            for(int k=1;k<=i;k++){
                vec.pop_back();
            }
        }    
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> m;
        for(int i = 0;i<candidates.size();i++){
            m[candidates[i]]++;
        }
        
        vector<pair<int, int> > cans;
        map<int, int>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            cans.push_back(*it);
        }
        
        vector<int> vec;
        vector<vector<int> > res;
        Find(target, cans, 0, vec, 0, res);
        
        return res;
    }
};
