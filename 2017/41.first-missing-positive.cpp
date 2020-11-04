/*
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive
 *
 * Hard (25.34%)
 * Total Accepted:    98060
 * Total Submissions: 386939
 * Testcase Example:  '[]'
 *
 * 
 * Given an unsorted integer array, find the first missing positive integer.
 * 
 * 
 * 
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * 
 * 
 * 
 * Your algorithm should run in O(n) time and uses constant space.
 * 
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0){
                nums[i] = n+1;
            }
        }
        
        for(int i=0;i<n;i++){
            int j = abs(nums[i]);
            if(j>=1&&j<=n){
                nums[j-1] = -abs(nums[j-1]);
            }
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                return i + 1;
            }
        }
        
        return n + 1;
    }
};
