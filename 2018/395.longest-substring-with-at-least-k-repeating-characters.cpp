/*
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters
 *
 * Medium (35.53%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"aaabb"\n3'
 *
 * 
 * Find the length of the longest substring T of a given string (consists of
 * lowercase letters only) such that every character in T appears no less than
 * k times.
 * 
 * 
 * Example 1:
 * 
 * Input:
 * s = "aaabb", k = 3
 * 
 * Output:
 * 3
 * 
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s = "ababbc", k = 2
 * 
 * Output:
 * 5
 * 
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
 * repeated 3 times.
 * 
 * 
 */
class Solution {
public:
    int longestSubstring(string s, int k) {
		if(s.size() < k) { return 0; }        
		map<char, int> m;
		for(auto c : s){
			m[c]++;
		}

		set<char> st;
		for(auto p : m){
			if(p.second < k){
				st.insert(p.first);
			}
		}

		if(st.empty()){
			return s.size();
		}

		int start = 0;
		int max = 0;
		for(int i=0; i<s.size(); i++){
			if(!st.count(s[i])){ continue; }

			int len = i - start;
			if(len > max){
				int val = longestSubstring(s.substr(start, len), k);
				max = max > val ? max : val;
			}

			start = i + 1;
		}

		if(s.size() > start){
			int val = longestSubstring(s.substr(start), k);
			max = max > val ? max : val;
		}

		return max; 
    }
};
