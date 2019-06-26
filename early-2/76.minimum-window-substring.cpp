/*
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring
 *
 * Hard (24.93%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"a"\n"a"'
 *
 * 
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * 
 * 
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * 
 * 
 * Minimum window is "BANC".
 * 
 * 
 * 
 * Note:
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * 
 * 
 * If there are multiple such windows, you are guaranteed that there will
 * always be only one unique minimum window in S.
 * 
 */
class Solution {
public:
    string minWindow(string s, string t) {
		if(t.empty()) { return s.empty() ? "" : s.substr(0,1); }
		map<char, int>  m;
		for(auto c : t){
			m[c]++;
		}

		int count = t.size();
		int start = 0;

		string res; 
		for(int i=0; i < s.size(); i++){
			char c = s[i];
			m[c]--;

			if(m[c] >= 0){ 
				count--; 
			}

			if(count==0){
				while(start <= i && m[s[start]] < 0){
					m[s[start]]++;
					start++;
				}

				if(res.empty() || res.size() > i - start + 1){
					res = s.substr(start, i - start + 1);
				}
			}
		}

		return res;
    }
};
