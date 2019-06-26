/*
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row
 *
 * Easy (60.16%)
 * Total Accepted:    29200
 * Total Submissions: 48534
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image
 * below. 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * 
 * 
 * 
 * Note:
 * 
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 * 
 * 
 */
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int pos[] = { 
            2, 3, 3, 2, 1, 2, 2,   
            2, 1, 2, 2, 2, 3, 3,
            1, 1, 1, 1, 2, 1,
            1, 3, 1, 3, 1, 3,
        };
        
        map<char, int> m;
        for(int i=0;i<26;i++) { m.insert(make_pair('a'+i, pos[i])); }
        
        vector<string> res;
        for(auto w : words){
            int p = 0;
            for(auto c : w) {
                if(!p) { p = m[tolower(c)]; }
                else if(p!= m[tolower(c)]) { p = -1; break; }
            }
            
            if(p>=0) { res.push_back(w); }
        }
        
        return res;
    }
};
