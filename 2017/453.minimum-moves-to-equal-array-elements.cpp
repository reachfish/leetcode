/*
 * [453] Minimum Moves to Equal Array Elements
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements
 *
 * Easy (46.88%)
 * Total Accepted:    25422
 * Total Submissions: 54222
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array of size n, find the minimum number of moves
 * required to make all array elements equal, where a move is incrementing n -
 * 1 elements by 1.
 * 
 * Example:
 * 
 * Input:
 * [1,2,3]
 * 
 * Output:
 * 3
 * 
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 * 
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * 
 */
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = INT_MAX;
        for(int i=0;i<nums.size();i++) { min = min < nums[i] ? min : nums[i]; }
        int count = 0;
        for(int i=0;i<nums.size();i++) { count += nums[i] - min; }
        return count;
    }
};
