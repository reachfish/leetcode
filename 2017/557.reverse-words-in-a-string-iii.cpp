/*
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii
 *
 * Easy (60.26%)
 * Total Accepted:    22128
 * Total Submissions: 36721
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 * 
 */
class Solution {
public:
    void swapWord(string &s, int b, int e){
        while(b<e){
            int t = s[b];
            s[b++] = s[e];
            s[e--] = t;
        }    
    }
    
    string reverseWords(string s) {
        int b = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                swapWord(s, b, i-1);
                b = i + 1;
            }
        }
        
        swapWord(s, b, s.size()-1);
        
        return s;
    }
};
