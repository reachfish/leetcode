/*
 * [556] Next Greater Element III
 *
 * https://leetcode.com/problems/next-greater-element-iii
 *
 * Medium (28.06%)
 * Total Accepted:    4708
 * Total Submissions: 16773
 * Testcase Example:  '12'
 *
 * 
 * Given a positive 32-bit integer n, you need to find the smallest 32-bit
 * integer which has exactly the same digits existing in the integer n and is
 * greater in value than n. If no such positive 32-bit integer exists, you need
 * to return -1.
 * 
 * Example 1:
 * 
 * Input: 12
 * Output: 21
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 21
 * Output: -1
 * 
 * 
 */
class Solution {
public:
    int nextGreaterElement(int n) {
        if(n<10){
            return -1;
        }
        
        int num = n;
        vector<int> digits;
        while(n){
            int d = n % 10;
            if(!digits.empty()&&d<digits.back()){
                break;
            }
            else{
                digits.push_back(d);
                n /= 10;
            }
        }
        
        if(!n){
            return -1;
        }
        
        int d = n%10;
        n /= 10;
        
        int i = 0;
        for(;i<digits.size();i++){
            if(digits[i]>d){
                digits.insert(digits.begin()+i, d);
                break;
            }
        }
        
        int tmp = digits[i+1];
        digits.erase(digits.begin()+i+1);
        digits.insert(digits.begin(), tmp);
        
        int res = 0;
        int power = 1;
        
        for(int i=digits.size()-1;i>=0;i--){
            res += digits[i] * power;
            power *= 10;
        }
        
        res += n * power;
        
        return res > num ? res : -1;
    }
};
