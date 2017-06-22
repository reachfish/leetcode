/*
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string
 *
 * Hard (24.37%)
 * Total Accepted:    68973
 * Total Submissions: 283049
 * Testcase Example:  '""\n""\n""'
 *
 * 
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 * 
 * 
 * 
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 * 
 * 
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 * 
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1+len2!=s3.size()){
            return false;
        }
        
        bool a[len1+1][len2+1] = {false};
        a[0][0] = true;
        for(int i=1;i<=len1;i++){
            a[i][0] = a[i-1][0] && s1[i-1] == s3[i-1];
        }
        for(int j=1;j<=len2;j++){
            a[0][j] = a[0][j-1] && s2[j-1] == s3[j-1];
        }
        
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                a[i][j] = (a[i-1][j] && s1[i-1] == s3[i+j-1]) || (a[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        
        return a[len1][len2];
    }
};
