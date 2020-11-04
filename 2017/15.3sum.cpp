/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum
 *
 * Medium (21.53%)
 * Total Accepted:    213295
 * Total Submissions: 990892
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum
 *
 * Medium (21.53%)
 * Total Accepted:    213295
 * Total Submissions: 990892
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());        
        int n = nums.size();
        int i = 0;
        while(i<n){
            int j = i + 1;
            int k = n - 1;
            while(j<k){
                int d = nums[i] + nums[j] + nums[k];
                if(d > 0){
                    k--;
                }
                else if(d < 0){
                    j++;
                }
                else{
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    res.push_back(v);

                    j++;
                    k--;

                    while(j<k && nums[j] == nums[j-1]) { j++; }
                    while(j<k && nums[k] == nums[k+1]) { k--; }
                }
            }

            i++;
            while(i<n && nums[i] == nums[i-1]) { i++; }
        }

        return res;
    }
};

