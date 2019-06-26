/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say
 *
 * Easy (33.95%)
 * Total Accepted:    134751
 * Total Submissions: 396943
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * 
 * 
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * 
 * 
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * Example 1:
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 4
 * Output: "1211"
 * 
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        if(n<=0) { return "1"; }
        string s = "1";
        for(int k=1;k<n;k++){
            string tmp;
            int start = 0;
            for(int i=0;i<s.size();i++){
                if(i && s[i]!=s[i-1]){
                    tmp += to_string(i-start);
                    tmp.push_back(s[i-1]);
                    start = i;
                }
                
                if(i==s.size()-1){
                    tmp += to_string(i-start+1);
                    tmp.push_back(s[i]);
                }
            }
            
            s = tmp;
        }
        
        return s;
    }
};
