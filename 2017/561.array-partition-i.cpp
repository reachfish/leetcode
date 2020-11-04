/*
 * [561] Array Partition I
 *
 * https://leetcode.com/problems/array-partition-i
 *
 * Easy (68.65%)
 * Total Accepted:    19716
 * Total Submissions: 28715
 * Testcase Example:  '[1,4,3,2]'
 *
 * 
 * Given an array of 2n integers, your task is to group these integers into n
 * pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of
 * min(ai, bi) for all i from 1 to n as large as possible.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,4,3,2]
 * 
 * Output: 4
 * Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3,
 * 4).
 * 
 * 
 * 
 * Note:
 * 
 * n is a positive integer, which is in the range of [1, 10000].
 * All the integers in the array will be in the range of [-10000, 10000].
 * 
 * 
 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        vector<int> count(20001, 0);
        for(int i=0;i<nums.size();i++){
            count[nums[i]+10000]++;
        }
        

        int size1 = count.size();
        int size2 = nums.size();
        int i = 0, j = 0;
        while(1){
            while(i<size1 && !count[i])
                i++;
                
            if(i==size1){
                break;
            }
            
            int c = (!(j & 1) & count[i]) + (count[i] >> 1);
            if(c){
                sum += (i-10000) * c;
            }
            
            j += count[i];
            if(j>=size2){
                break;
            }
            
            i++;
        }
        
        return sum;
    }
};
