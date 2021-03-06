/*
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum
 *
 * Medium (38.64%)
 * Total Accepted:    21025
 * Total Submissions: 54403
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * 
 * Note:
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<100 * 200 / 2 + 1> bits(1);
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            sum += num;
            bits |= bits << num;
        }
        
        return !(sum & 1) && bits[sum>>1];
    }
};
