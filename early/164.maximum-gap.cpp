/*
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap
 *
 * Hard (29.26%)
 * Total Accepted:    47075
 * Total Submissions: 160891
 * Testcase Example:  '[]'
 *
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 * 
 * Try to solve it in linear time/space.
 * 
 * Return 0 if the array contains less than 2 elements.
 * 
 * You may assume all elements in the array are non-negative integers and fit
 * in the 32-bit signed integer range.
 * 
 * Credits:Special thanks to @porker2008 for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if(size < 2){
            return 0;
        }
        
        int min = nums[0];
        int max = nums[0];
        for(int i=1;i<nums.size();i++){
                if(min>nums[i]){
                    min = nums[i];
                }
                if(max<nums[i]){
                    max = nums[i];
                }
        }
        
        int maxDif = max - min;
        if (maxDif == 0){
            return 0;
        }
        
        vector<int> minBuck(size+1, -1);
        vector<int> maxBuck(size+1, -1);
        for(int i=0;i<size;i++){
            int val = nums[i];
            int j = int((val - min+0.0f) * size / maxDif);
            if(minBuck[j]==-1){
                minBuck[j] = maxBuck[j] = val;
            }
            else{
                minBuck[j] = minBuck[j] < val ? minBuck[j] : val;
                maxBuck[j] = maxBuck[j] > val ? maxBuck[j] : val;
            }
        }
        
        int ret = 0;
        int cur;
        for(int i= 0;i<size+1;i++){
            if(minBuck[i]==-1){
                continue;
            }
            
            if(i){
                int diff = minBuck[i] - cur;
                ret = ret > diff ? ret : diff;
            }
            cur = maxBuck[i];
        }
        
        return ret;
    }
};
