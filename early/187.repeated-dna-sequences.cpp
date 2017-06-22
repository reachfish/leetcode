/*
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences
 *
 * Medium (30.91%)
 * Total Accepted:    74163
 * Total Submissions: 239949
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * 
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
 * T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 * 
 * 
 * For example,
 * 
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 * 
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 * 
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<int, int> m;
        vector<string> ret;
        int i = 0;
        int t = 0;
        while(i<9){
            t = t << 3 | s[i++] & 7;
        }
        
        while(i<s.size()){
            if(m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++==1){
                ret.push_back(s.substr(i-10,10));
            }
        }
        
        return ret;
    }
};
