/*
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses
 *
 * Hard (22.99%)
 * Total Accepted:    94449
 * Total Submissions: 410786
 * Testcase Example:  '""'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * 
 * For "(()", the longest valid parentheses substring is "()", which has length
 * = 2.
 * 
 * 
 * Another example is ")()())", where the longest valid parentheses substring
 * is "()()", which has length = 4.
 * 
 */
class Solution {
public:
    int getCount(const vector<int>& count, int i){
        if (i<0) {
            return 0;
        }
        
        return count[i];
    }
    int longestValidParentheses(string s) {
        size_t len = s.size();
        vector<int> count(len, 0);
        int max = 0;
        for(size_t i=1;i<len;i++){
            if(s.at(i)=='('){
                continue;
            }
            
            int val = 0;
            if(s.at(i-1)=='('){ //...()
                val = getCount(count, i-2) + 2;
            }
            else{ //...((...))
                 int pri = count[i-1];
                 if(pri && pri < i){
                    int left = i - 1 - pri;
                    if(s.at(left)=='('){
                        val = getCount(count, left-1) + pri + 2;
                    }
                 }
            }
            
            count[i] = val;
            if (val > max){
                max = val;
            }
        }
        
        return max;
    }
};
