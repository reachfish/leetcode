/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest
 *
 * Medium (30.91%)
 * Total Accepted:    127976
 * Total Submissions: 414058
 * Testcase Example:  '[0,0,0]\n1'
 *
 * Given an array S of n integers, find three integers in S such that the sum
 * is closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * 
 * 
 * ⁠   For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 * ⁠   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 */
/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest
 *
 * Medium (30.91%)
 * Total Accepted:    127976
 * Total Submissions: 414058
 * Testcase Example:  '[0,0,0]\n1'
 *
 * Given an array S of n integers, find three integers in S such that the sum
 * is closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * 
 * 
 * ⁠   For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 * ⁠   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min = INT_MAX;        
        int sum = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int j = i + 1; 
            int k = n - 1;
            while(j<k){
                int d = nums[i] + nums[j] + nums[k] - target;
                if(d == 0){
                    return target;
                }

                if(abs(d) < min){
                    min = abs(d);
                    sum = d + target;
                }

                if(d > 0) { k--; }
                else { j++; }
            }
        }

        return sum;
    }
};

