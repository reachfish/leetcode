/*
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number
 *
 * Medium (22.27%)
 * Total Accepted:    72997
 * Total Submissions: 327818
 * Testcase Example:  '[1]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    
    static long getConcat(int a, int b){
        long power = 1;
        long res = b;
        do{
            power *= 10;
            b /= 10;
        }while(b);
        
        res += a * power;
        
        return res;
    }
    
    static bool compare(int a, int b){
       return getConcat(a, b) > getConcat(b, a);
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), Solution::compare);
        
        if(!nums.empty() && nums[0]==0){
            return "0";
        }
        
        string s;
        for(int i=0;i<nums.size();i++) s += to_string(nums[i]);

        return s;
    }
};
