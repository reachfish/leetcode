/*
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways
 *
 * Medium (19.38%)
 * Total Accepted:    118957
 * Total Submissions: 613871
 * Testcase Example:  '""'
 *
 * 
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 
 * Given an encoded message containing digits, determine the total number of
 * ways to decode it.
 * 
 * 
 * 
 * For example,
 * Given encoded message "12",
 * it could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * 
 * The number of ways decoding "12" is 2.
 * 
 */
class Solution {
public:
    int numDecodings(string s) {
        int pre = 0;
        int cur = 0;
        
        for(int i=0;i<s.size();i++){
            if(!isdigit(s[i])) { return 0; }
            
            if(!i){
                if(s[i]=='0') {return 0;}
                pre = cur = 1;
                continue;
            }
            
            int next = s[i]=='0' ? 0 : cur;
            int val = atoi(s.substr(i-1,2).c_str());
            if(val >= 10 && val <= 26 && !(i+1<s.size()&&s[i+1]=='0')){
                next += pre;
            }
            
            pre = cur;
            cur = next;
        }
        
        return cur;
    }
};
