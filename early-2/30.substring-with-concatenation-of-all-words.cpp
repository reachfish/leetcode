/*
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words
 *
 * Hard (21.90%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * 
 * 
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 * 
 * 
 * 
 * You should return the indices: [0,9].
 * (order does not matter).
 * 
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		int n = s.size();
		int num = words.size();
		int len = words[0].size();

		map<string, int> m;
		for(auto w : words){
			m[w]++;
		}

		vector<int> index;
		for(int i=0; i<=n-num*len; i++){
			int j = 0;
			map<string, int> tm;
			for(;j<num;j++){
				string word = s.substr(i+j*len, len);
				if(!m.count(word) || m[word] <= tm[word]){
					break;
				}

				tm[word]++;
			}

			if(j==num){
				index.push_back(i);
			}
		}

		return index;
    }
};
