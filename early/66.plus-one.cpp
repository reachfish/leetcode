/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one
 *
 * Easy (38.17%)
 * Total Accepted:    168386
 * Total Submissions: 441115
 * Testcase Example:  '[0]'
 *
 * Given a non-negative integer represented as a non-empty array of digits,
 * plus one to the integer.
 * 
 * You may assume the integer do not contain any leading zero, except the
 * number 0 itself.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        
        int d = 1;
        for(int i=digits.size()-1;i>=0;i--){
            int v = d + digits[i];
            if(v >= 10){
                v -= 10;
                d = 1;
            }
            else{
                d = 0;
            }
            
            res.insert(res.begin(), v);
        }
        
        if(d){
            res.insert(res.begin(), d);
        }
        
        return res;
    }
};
