/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray
 *
 * Medium (25.31%)
 * Total Accepted:    99036
 * Total Submissions: 391329
 * Testcase Example:  '[-2]'
 *
 * 
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest product.
 * 
 * 
 * 
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 * 
 */
class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int max = INT_MIN;
        
        int cur_min = 1;
        int cur_max = 1;
        
        vector<int> v(3);
        for(int i=0;i<nums.size();i++){
            v[0] = nums[i];
            v[1] = nums[i] * cur_min;
            v[2] = nums[i] * cur_max;
            
            cur_min = * min_element(v.begin(), v.end());
            cur_max = * max_element(v.begin(), v.end());
            
            max = max > cur_max ? max : cur_max;
        }
        
        return max;
    }
};
