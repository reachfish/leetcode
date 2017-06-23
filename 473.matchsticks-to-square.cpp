/*
 * [473] Matchsticks to Square
 *
 * https://leetcode.com/problems/matchsticks-to-square
 *
 * Medium (34.57%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * Remember the story of Little Match Girl? By now, you know exactly what
 * matchsticks the little match girl has, please find out a way you can make
 * one square by using up all those matchsticks. You should not break any
 * stick, but you can link them up, and each matchstick must be used exactly
 * one time.
 * 
 * ⁠Your input will be several matchsticks the girl has, represented with their
 * stick length. Your output will either be true or false, to represent whether
 * you could make one square using all the matchsticks the little match girl
 * has.
 * 
 * Example 1:
 * 
 * Input: [1,1,2,2,2]
 * Output: true
 * 
 * Explanation: You can form a square with length 2, one side of the square
 * came two sticks with length 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [3,3,3,3,4]
 * Output: false
 * 
 * Explanation: You cannot find a way to form a square with all the
 * matchsticks.
 * 
 * 
 * 
 * Note:
 * 
 * The length sum of the given matchsticks is in the range of 0 to 10^9.
 * The length of the given matchstick array will not exceed 15.
 * 
 * 
 */
class Solution {
public:
    bool dfs(vector<int> &nums, int index, int *s, int target){
        if(index==nums.size()) {
            for(int i=0;i<4;i++){
                if(s[i] != target) { return false; }
            }

            return true;
        }

        for(int i=0;i<4;i++){
            if(s[i] + nums[index] > target) { continue; }
            s[i] += nums[index];
            if(dfs(nums, index + 1, s, target)) { return true; }
            s[i] -= nums[index];
        }

        return false;
    }

    bool makesquare(vector<int>& nums) {
        int sum = 0;        
        for(auto n : nums) { sum += n; }
        if(sum==0 || sum%4 != 0) { return false; }

        int s[4] = {0,0,0,0};

        sort(nums.begin(), nums.end(), [](int a, int b){ return a > b;});

        return dfs(nums, 0, s, sum/4);
    }
};

