/*
 * [592] Fraction Addition and Subtraction
 *
 * https://leetcode.com/problems/fraction-addition-and-subtraction
 *
 * Medium (46.62%)
 * Total Accepted:    2538
 * Total Submissions: 5444
 * Testcase Example:  '"-1/2+1/2"'
 *
 * Given a string representing an expression of fraction addition and
 * subtraction, you need to return the calculation result in string format. The
 * final result should be irreducible fraction. If your final result is an
 * integer, say 2, you need to change it to the format of fraction that has
 * denominator 1. So in this case, 2 should be converted to 2/1.
 * 
 * Example 1:
 * 
 * Input:"-1/2+1/2"
 * Output: "0/1"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:"-1/2+1/2+1/3"
 * Output: "1/3"
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:"1/3-1/2"
 * Output: "-1/6"
 * 
 * 
 * 
 * Example 4:
 * 
 * Input:"5/3+1/3"
 * Output: "2/1"
 * 
 * 
 * 
 * Note:
 * 
 * The input string only contains '0' to '9', '/', '+' and '-'. So does the
 * output.
 * Each fraction (input and output) has format ±numerator/denominator. If the
 * first input fraction or the output is positive, then '+' will be omitted.
 * The input only contains valid irreducible fractions, where the numerator and
 * denominator of each fraction will always be in the range [1,10]. If the
 * denominator is 1, it means this fraction is actually an integer in a
 * fraction format defined above. 
 * The number of given fractions will be in the range [1,10].
 * The numerator and denominator of the final result are guaranteed to be valid
 * and in the range of 32-bit int.
 * 
 * 
 */
class Solution {
public:
    void add(int &resNum, int &resDen, int curNum, int curDen){
        if(curNum == 0) { return ; }
        int num = resNum * curDen + curNum * resDen; 
        int den = resDen * curDen ;
        int a = abs(num), b = den; 
        while(a%b){
            int tmp = a % b;
            a = b;
            b = tmp;
        }

        resNum = num / b;
        resDen = den / b;
    }

    string fractionAddition(string expression) {
        int sig = 1;
        int curNum = 0;
        int curDen = 0; 
        int resNum = 0;
        int resDen = 1;
        bool deno = false;
        for(int i = 0; i<expression.size(); i++) {
            char c = expression[i];
            switch(c){
                case '/': deno = true; break;
                case '+': 
                case '-': 
                          add(resNum, resDen, curNum * sig, curDen);
                          sig = c == '+' ? 1 : -1;
                          curNum = curDen = 0;
                          deno = false;
                          break;
                default:
                          if(!deno) { curNum = curNum * 10 + (c - '0'); }
                          else { curDen = curDen * 10 + (c-'0'); }
                          if(i == expression.size() - 1) { 
                                add(resNum, resDen, curNum * sig, curDen);
                          }
            }
        }

        return to_string(resNum) + "/" + to_string(resDen);
    }
};
