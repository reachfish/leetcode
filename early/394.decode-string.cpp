/*
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string
 *
 * Medium (41.00%)
 * Total Accepted:    29473
 * Total Submissions: 71874
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 
 * Given an encoded string, return it's decoded string.
 * 
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * 
 * Examples:
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 */
/*
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string
 *
 * Medium (41.00%)
 * Total Accepted:    29473
 * Total Submissions: 71874
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 
 * Given an encoded string, return it's decoded string.
 * 
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * 
 * Examples:
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 */
class Solution {
public:
    string decodeString(string s) {
        size_t pos = s.find('[');        
        if(pos == string::npos) { return s; }
        int i = 0;
        while(!isdigit(s[i])) { i++; }
        int val = atoi(s.substr(i, pos - i).c_str());

        pos++;
        int j = pos;
        int cnt = 1;
        while(cnt){
            switch(s[j++]){
                case '[': cnt++; break;
                case ']': cnt--; break;
            }
        }

        string t;
        string part = decodeString(s.substr(pos, j - pos - 1));
        for(int i=0;i<val;i++){
            t += part;
        }

        return decodeString(s.substr(0, i)) + t + decodeString(s.substr(j));
    }
};

