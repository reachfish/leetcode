/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome
 *
 * Easy (25.99%)
 * Total Accepted:    160035
 * Total Submissions: 615766
 * Testcase Example:  '""'
 *
 * 
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * 
 * 
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * 
 * 
 * 
 * Note:
 * Have you consider that the string might be empty? This is a good question to
 * ask during an interview.
 * 
 * For the purpose of this problem, we define empty string as valid palindrome.
 * 
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i<j){
            while(i<j&&!isalnum(s[i])){
                i++;
            }
            
            while(i<j&&!isalnum(s[j])){
                j--;
            }
            
            if(i<j){
                if(tolower(s[i])!=tolower(s[j])){
                    return false;
                }
                i++;
                j--;
            }
        }
        
        return true;
    }
};
