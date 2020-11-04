/*
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum
 *
 * Medium (43.82%)
 * Total Accepted:    19922
 * Total Submissions: 45464
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.  
 * 
 * 
 * Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array is positive and will not exceed 20. 
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */

class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.empty()) { return S == 0 ? 1 : 0; }
        int n = nums.size();
        
        map<int, int> m;
        m[0] = 1;
        for(int i=0;i<nums.size();i++){
            map<int, int> tmp;
            for(auto p : m) {
                tmp[p.first + nums[i]] += p.second;
                tmp[p.first - nums[i]] += p.second;
            }
            m = tmp;
        }
        
        return m[S];
    }
};
