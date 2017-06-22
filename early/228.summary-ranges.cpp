/*
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges
 *
 * Medium (29.24%)
 * Total Accepted:    77042
 * Total Submissions: 263452
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * 
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;

        int cur = INT_MIN;
        int min = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(!i){
                cur = min = nums[i];
                continue;
            }
            
            if(nums[i]==cur+1){
                cur = nums[i];
                continue;
            }
            
            if(min==cur){
                res.push_back(to_string(cur));
            }
            else{
                res.push_back(to_string(min) + "->" + to_string(cur));
            }
            
            cur = min = nums[i];
        }
        
        if(!nums.empty()){
            if(min==cur){
                res.push_back(to_string(cur));
            }
            else{
                res.push_back(to_string(min) + "->" + to_string(cur));
            }
        }
        
        return res;
    }
};
