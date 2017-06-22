/*
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses
 *
 * Medium (26.84%)
 * Total Accepted:    82968
 * Total Submissions: 309079
 * Testcase Example:  '"0000"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * 
 * For example:
 * Given "25525511135",
 * 
 * 
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 * 
 */
class Solution {
public:
    bool isValid(const string &s){
        if(s.empty()||s.size() > 3) return false;
        if(s.size()>=2 && s[0] =='0') return false;
        if(atoi(s.c_str()) > 255) return false;
        
        return true;
    }
    
    void helper(string s, int num, string pre, vector<string>& res){
        if(num==4){
            if(isValid(s)){
                res.push_back(pre + "." + s);
            }
        }
        else{
            for(int len=1;len<=3 && len <= s.size();len++){
                string str = s.substr(0, len);
                if(isValid(str)){
                    helper(s.substr(len), num + 1,  pre.empty() ? str : pre + "." + str, res);
                }
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(s, 1, "", res);
        
        return res;
    }
};
