/*
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number
 *
 * Easy (27.70%)
 * Total Accepted:    33718
 * Total Submissions: 121735
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 */
class Solution {
public:
   
    int thirdMax(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            int pos = v.size(); 
            for(int j=0;j<v.size();j++){
                if(nums[i] > v[j]) { pos = j; break; }
                else if(nums[i]==v[j]) { pos = -1; break; }
            }
            if(pos >= 0 && pos < 3){
                v.insert(v.begin() + pos, nums[i]);
                if(v.size() > 3) { v.pop_back(); }
            }
        }
        
        return v.size() == 3 ? v[2] : (v.empty() ? INT_MIN : v[0]);
    }
};
