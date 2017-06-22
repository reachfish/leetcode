/*
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii
 *
 * Medium (47.39%)
 * Total Accepted:    11625
 * Total Submissions: 24532
 * Testcase Example:  '[1,2,1]'
 *
 * 
 * Given a circular array (the next element of the last element is the first
 * element of the array), print the Next Greater Number for every element. The
 * Next Greater Number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, output -1 for this
 * number.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; The number 2 can't find
 * next greater number; The second 1's next greater number needs to search
 * circularly, which is also 2.
 * 
 * 
 * 
 * Note:
 * The length of given array won't exceed 10000.
 * 
 */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        map<int, int> m;
        stack<int> stk;
        
        for(int k=0;k<2;k++){
            for(int i=0;i<nums.size();i++){
                int num = nums[i];
                while(!stk.empty()&&nums[stk.top()]<num){
                    if(!m.count(stk.top())) { m[stk.top()] = i; }
                    stk.pop();
                }
            
                stk.push(i);
            }
        }
        
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            res.push_back(m.count(i) ? nums[m[i]] : -1);
        }
        
        return res;
    }
};
