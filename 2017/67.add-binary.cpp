/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary
 *
 * Easy (31.85%)
 * Total Accepted:    141748
 * Total Submissions: 445049
 * Testcase Example:  '"0"\n"0"'
 *
 * 
 * Given two binary strings, return their sum (also a binary string).
 * 
 * 
 * 
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 * 
 */
class Solution {
public:
    void addVal(string &res, int &flag, int val){
        val += flag;
        if(val>=2){
            flag = 1;
            val -= 2;
        } 
        else{
            flag = 0;
        }
        
        res = to_string(val) + res;
    }
    
    string addBinary(string a, string b) {
        int flag = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        string res;
        while(i>=0&&j>=0){
            addVal(res, flag, (a[i--]-'0')+(b[j--]-'0'));
        }
        
        while(i>=0){
            addVal(res, flag, (a[i--]-'0'));
        }
        
        while(j>=0){
            addVal(res, flag, (b[j--]-'0'));
        }
        
        if(flag > 0){
            addVal(res, flag, 0);
        }
        
        return res;
    }
};
