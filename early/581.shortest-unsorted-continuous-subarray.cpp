/*
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray
 *
 * Easy (29.73%)
 * Total Accepted:    7519
 * Total Submissions: 25279
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.  
 * 
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * 
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * 
 * Note:
 * 
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means <=. 
 * 
 * 
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int min = INT_MAX;
        int max = INT_MIN;
        
        int start = -1;
        int end = -1;
        for(int i=0;i<nums.size();i++){
            if(!i) { max = nums[i]; continue; }
            if(nums[i] >= max) { max = nums[i]; continue; }
            
            end = i;
            if(start < 0) {
                int j = i - 1;
                while(j>=0&&nums[j] > nums[i])
                    j--;
                    
                start = j + 1; 
                continue; 
            }
            
            if(nums[i] >= min || start == 0) { continue; }
            
            int j = start - 1;
            for(;j>=0;j--){
                if(nums[i]>=nums[j]){
                    break;
                }
            }
            
            start = j + 1;
            
            min = nums[i];
        }
        
        return end == start ? 0 : end - start + 1;
    }
};
