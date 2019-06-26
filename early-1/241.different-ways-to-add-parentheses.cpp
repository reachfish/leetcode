/*
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses
 *
 * Medium (43.20%)
 * Total Accepted:    43023
 * Total Submissions: 99596
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 * 
 * Example 1
 * Input: "2-1-1". 
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 * Output: [0, 2]
 * 
 * Example 2
 * Input: "2*3-4*5" 
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 * Output: [-34, -14, -10, -10, 10] 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:

    int cal(int a, char c, int b){
        switch(c){
            case '+': return a + b;
            case '-': return a - b;
            default: return a*b;
        }
    }
    
    
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if(input.empty()) { return res; }
        
       
        for(int i=0;i<input.size();i++){
            if(!isdigit(input[i])){
               vector<int> left = diffWaysToCompute(input.substr(0, i));
               vector<int> right = diffWaysToCompute(input.substr(i+1, input.size()-i-1));
               for(auto a :left){
                   for(auto b : right){
                       res.push_back(cal(a, input[i], b));
                   }
               }
            }
        }
        
        if(res.empty()){
            res.push_back(atoi(input.c_str()));
        }
        
        return res;
    }
};
