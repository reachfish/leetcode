/*
 * [537] Complex Number Multiplication
 *
 * https://leetcode.com/problems/complex-number-multiplication
 *
 * Medium (65.14%)
 * Total Accepted:    8674
 * Total Submissions: 13317
 * Testcase Example:  '"1+1i"\n"1+1i"'
 *
 * 
 * Given two strings representing two complex numbers.
 * 
 * 
 * You need to return a string representing their multiplication. Note i2 = -1
 * according to the definition.
 * 
 * 
 * Example 1:
 * 
 * Input: "1+1i", "1+1i"
 * Output: "0+2i"
 * Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert
 * it to the form of 0+2i.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "1+-1i", "1+-1i"
 * Output: "0+-2i"
 * Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert
 * it to the form of 0+-2i.
 * 
 * 
 * 
 * Note:
 * 
 * The input strings will not have extra blank.
 * The input strings will be given in the form of a+bi, where the integer a and
 * b will both belong to the range of [-100, 100]. And the output should be
 * also in this form.
 * 
 * 
 */
class Solution {
public:
    void get(string a, int &x, int &y){
        x = y = 0;
        if(a.empty()) { return; }
        
        int sig = 1;
        int start = -1;
        for(int i=0;i<a.size();i++){
            char c = a[i];
            switch(c){
                case '-':
                            sig *= -1;
                case '+':
                case 'i':
                            if(start >= 0){
                                int val = atoi(a.substr(start, i - start).c_str()) * sig;
                                if(c=='i') { y += val; }
                                else { x += val; }
                                
                                start = -1;
                                sig = 1;
                            }
                            
                            break;
                default:
                            if(start<0) { start = i; }
                            if(i==a.size()-1) { x += atoi(a.substr(start, i-start+1).c_str()) * sig; }
            }
        }
    }
    string complexNumberMultiply(string a, string b) {
        int x1, y1, x2, y2;
        get(a, x1, y1);
        get(b, x2, y2);
        
        int x = x1 * x2 - y1 * y2;
        int y = x1 * y2 + x2 * y1;
        
        return to_string(x) + "+" + to_string(y) + "i";
    }
};
