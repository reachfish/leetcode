/*
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern
 *
 * Easy (32.78%)
 * Total Accepted:    76597
 * Total Submissions: 233658
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * ⁠Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Examples:
 * 
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * 
 * 
 * 
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 * 
 * 
 * Credits:Special thanks to @minglotus6 for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> s;
        int i = 0;
        int j = 0;
        for(;j<str.size();j++){
            if(str[j]==' '){
                if(j>i){
                    s.push_back(str.substr(i, j-i));        
                }
                i = j + 1;
            }
        }
        
        if(j>i){
            s.push_back(str.substr(i, j-i));
        }
        
        if(pattern.size()!=s.size()) return false;
        
        map<char, string> m1;
        map<string, char> m2;
        
        for(int i=0;i<pattern.size();i++){
            char a = pattern[i];
            string b = s[i];
            
            //a -> b
            if(m1.count(a)){
                if(m1[a]!=b) return false;
            }
            else{
                if(m2.count(b)) return false;
                
                m1[a] = b;
                m2[b] = a;
            }
        }
        
        return true;
    }
};
