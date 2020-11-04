/*
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break
 *
 * Medium (29.40%)
 * Total Accepted:    145549
 * Total Submissions: 494994
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words. You may assume the dictionary does
 * not contain duplicate words.
 * 
 * 
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 * 
 * 
 * 
 * Return true because "leetcode" can be segmented as "leet code".
 * 
 * 
 * 
 * UPDATE (2017/1/4):
 * The wordDict parameter had been changed to a list of strings (instead of a
 * set of strings). Please reload the code definition to get the latest
 * changes.
 * 
 */
/*
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break
 *
 * Medium (29.40%)
 * Total Accepted:    145549
 * Total Submissions: 494994
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words. You may assume the dictionary does
 * not contain duplicate words.
 * 
 * 
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 * 
 * 
 * 
 * Return true because "leetcode" can be segmented as "leet code".
 * 
 * 
 * 
 * UPDATE (2017/1/4):
 * The wordDict parameter had been changed to a list of strings (instead of a
 * set of strings). Please reload the code definition to get the latest
 * changes.
 * 
 */
typedef struct tree{
    map<char, struct tree*> childs;
    bool isWord;

    tree() { isWord = false; }
}tree;

class Solution {
private:

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        bool dp[s.size() + 1];
        for(int i=1;i<=s.size();i++) { dp[i] = false; }
        dp[0] = true;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j] && st.count(s.substr(j, i - j))) { dp[i] = true; break; }
            }
        }

        return dp[s.size()];
    }
};

