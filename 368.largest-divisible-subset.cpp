/*
 * [368] Largest Divisible Subset
 *
 * https://leetcode.com/problems/largest-divisible-subset
 *
 * Medium (33.62%)
 * Total Accepted:    23626
 * Total Submissions: 70272
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a set of distinct positive integers, find the largest subset such that
 * every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj
 * % Si = 0.
 * 
 * 
 * If there are multiple solutions, return any subset is fine.
 * 
 * 
 * Example 1:
 * 
 * nums: [1,2,3]
 * 
 * Result: [1,2] (of course, [1,3] will also be ok)
 * 
 * 
 * 
 * Example 2:
 * 
 * nums: [1,2,4,8]
 * 
 * Result: [1,2,4,8]
 * 
 * 
 * 
 * Credits:Special thanks to @Stomach_ache for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int max(int a, int b){
        return a > b ? a : b;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) { return res; }
        sort(nums.begin(), nums.end());        
        int n = nums.size();
        int dp[n];
        memset(dp, 0, n);

        int Max = 0;
        int mi;
        for(int i=n-1;i>=0;i--){
            int cur = 1;
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i] == 0){
                    cur = max(cur, 1 + dp[j]); 
                }
            }
            dp[i] = cur;
            if(cur > Max){
                Max = cur;
                mi = i;
            }
        }

        int i = mi;
        while(dp[i] != 1){
            for(int j = i+1; j<n; j++){
                if(nums[j]%nums[i]==0&&dp[j]==dp[i]-1){
                    res.push_back(nums[i]);
                    i = j;
                    break;
                }
            }
        }

        res.push_back(nums[i]);

        return res;
    }
};
