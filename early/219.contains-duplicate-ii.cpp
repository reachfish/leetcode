/*
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii
 *
 * Easy (32.11%)
 * Total Accepted:    109504
 * Total Submissions: 341026
 * Testcase Example:  '[]\n0'
 *
 * 
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 * 
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i=0;i<nums.size();i++){
            int n = nums[i];
            if(m.count(n)&&(i-m[n])<=k){
                return true;
            }
            
            m[n] = i;
        }
        
        return false;
    }
};
