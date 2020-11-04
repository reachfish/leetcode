/*
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome
 *
 * Easy (45.28%)
 * Total Accepted:    39999
 * Total Submissions: 88335
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */
class Solution {
public:
    int longestPalindrome(string s) {
        int a[52];
        for(int i=0;i<52;i++){
            a[i] = 0;
        }
        
        for(int i=0;i<s.size();i++){
            int index = s[i] >= 'a' ?  s[i] - 'a' : s[i] - 'A' + 26;
            a[index]++;
        }
        
        int res = 0;
        bool odd = true;
        for(int i=0;i<52;i++){
            if(a[i]&1){
                res += odd ? a[i] : a[i] - 1;
                odd = false;
            }
            else{
                res += a[i];
            }
        }
        
        return res;
    }
};
