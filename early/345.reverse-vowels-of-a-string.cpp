/*
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string
 *
 * Easy (38.22%)
 * Total Accepted:    76104
 * Total Submissions: 199099
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * 
 * Example 1:
 * Given s = "hello", return "holle".
 * 
 * 
 * 
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 * 
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 */
class Solution {
public:
    string reverseVowels(string s) {
        string left;
        string right;
        
        int i = 0;
        int j = s.size() - 1;
        
        map<char, int> m;
        char vov[] = {'a', 'e', 'i', 'o', 'u'};
        for(int i=0;i<sizeof(vov)/sizeof(char);i++){
            m[vov[i]] = 1;
            m[char(vov[i]-'a'+'A')] = 1;
        }
        
        while(i<=j){
            while(i<=j&&!m[s[i]]){
                left += string(1,s[i++]);
            }
            
            while(i<=j&&!m[s[j]]){
                right = string(1,s[j--]) + right;
            }
            
            if(i<j){
                left += string(1,s[j--]);
                right = string(1,s[i++]) + right;
            }
            else if(i==j){
                left += string(1, s[i++]);   
            }
        }
        
        return left + right;
    }
};
