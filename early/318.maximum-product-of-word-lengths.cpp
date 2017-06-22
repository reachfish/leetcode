/*
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths
 *
 * Medium (43.67%)
 * Total Accepted:    48453
 * Total Submissions: 110958
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * 
 * ⁠   Given a string array words, find the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters.
 * ⁠   You may assume that each word will contain only lower case letters.
 * ⁠   If no such two words exist, return 0.
 * 
 * 
 * 
 * ⁠   Example 1:
 * 
 * 
 * ⁠   Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 * ⁠   Return 16
 * ⁠   The two words can be "abcw", "xtfn".
 * 
 * 
 * ⁠   Example 2:
 * 
 * 
 * ⁠   Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 * ⁠   Return 4
 * ⁠   The two words can be "ab", "cd".
 * 
 * 
 * ⁠   Example 3:
 * 
 * 
 * ⁠   Given ["a", "aa", "aaa", "aaaa"]
 * ⁠   Return 0
 * ⁠   No such pair of words.    
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> vec;
        for(int i=0;i<words.size();i++){
            int val = 0;
            for(int j=0;j<words[i].size();j++){
                val |= 1 << (words[i][j]-'a'); 
            }
            vec.push_back(val);
        }
        
        int res = 0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(!(vec[i]&vec[j])){
                    int len = words[i].size() * words[j].size();
                    res = res > len ? res : len;
                }
            }
        }
        
        return res;
    }
};
