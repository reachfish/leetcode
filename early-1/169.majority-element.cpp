/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element
 *
 * Easy (46.12%)
 * Total Accepted:    193209
 * Total Submissions: 418898
 * Testcase Example:  '[1]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty()){
            return -1;
        }
        
        int major = nums[0];
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==major){
                count++;
            }
            else{
                count--;
                if(count==0){
                    major = nums[i];
                    count = 1;
                }
            }
        }
        
        return major;
    }
};
