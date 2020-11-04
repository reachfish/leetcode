/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum
 *
 * Medium (26.43%)
 * Total Accepted:    116926
 * Total Submissions: 442364
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such
 * that a + b + c + d = target? Find all unique quadruplets in the array which
 * gives the sum of target.
 * 
 * Note: The solution set must not contain duplicate quadruplets.
 * 
 * 
 * 
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 */
/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum
 *
 * Medium (26.43%)
 * Total Accepted:    116926
 * Total Submissions: 442364
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such
 * that a + b + c + d = target? Find all unique quadruplets in the array which
 * gives the sum of target.
 * 
 * Note: The solution set must not contain duplicate quadruplets.
 * 
 * 
 * 
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int p = 0;
        while(p<n){
            int q = p + 1;
            while(q<n){
                int r = q + 1; 
                int s = n - 1;
                int val = nums[p] + nums[q] - target;
                while(r < s){
                    int d = val + nums[r] + nums[s];
                    if(d < 0) {
                        r++;
                    }
                    else if(d > 0){
                        s--;
                    }
                    else{
                        vector<int> v = { nums[p], nums[q], nums[r], nums[s] };
                        res.push_back(v);

                        r++;
                        s--;

                        while(r < s && nums[r] == nums[r-1]) { r++; }
                        while(r < s && nums[s] == nums[s+1]) { s--; }
                    }
                }

                q++;
                while(q<n && nums[q] == nums[q-1]) { q++; }
            }

            p++;
            while(p<n && nums[p] == nums[p-1]) { p++; }
        }

        return res;
    }
};

