/*
 * [462] Minimum Moves to Equal Array Elements II
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii
 *
 * Medium (51.25%)
 * Total Accepted:    14708
 * Total Submissions: 28700
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array, find the minimum number of moves required
 * to make all array elements equal, where a move is incrementing a selected
 * element by 1 or decrementing a selected element by 1.
 * 
 * You may assume the array's length is at most 10,000.
 * 
 * Example:
 * 
 * Input:
 * [1,2,3]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one
 * element):
 * 
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 * 
 * 
 */
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size() <= 1) { return 0; }
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size()/2];
        int count = 0;
        for(int i=0;i<nums.size();i++) { count += abs(nums[i] - mid); }
        return count;
    }
};
