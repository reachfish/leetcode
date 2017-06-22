/*
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate
 *
 * Easy (45.20%)
 * Total Accepted:    159166
 * Total Submissions: 352128
 * Testcase Example:  '[]'
 *
 * 
 * Given an array of integers, find if the array contains any duplicates. Your
 * function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
            if(m[*it]){
                return true;
            }
            m[*it] = 1;
        }
        
        return false;
    }
};
