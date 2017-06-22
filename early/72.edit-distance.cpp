/*
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance
 *
 * Hard (31.35%)
 * Total Accepted:    86814
 * Total Submissions: 276910
 * Testcase Example:  '""\n""'
 *
 * 
 * Given two words word1 and word2, find the minimum number of steps required
 * to convert word1 to word2. (each operation is counted as 1 step.)
 * 
 * 
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * 
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 * 
 */
class Solution {
public:
    int min(int a, int b){
        return a < b ? a : b;
    }
    
    int minDistance(string word1, string word2) {
        size_t len1 = word1.size();
        size_t len2 = word2.size();
        vector<vector<int> > dist(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i=0;i<=len1;i++)
        {
            dist[i][0] = i;
        }
        for(int j=0;j<=len2;j++)
        {
            dist[0][j] = j;
        }
        
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                int val = 1 + min(dist[i-1][j], dist[i][j-1]); 
                if(word1[i-1]==word2[j-1]){
                    dist[i][j] = min(val, dist[i-1][j-1]);
                }
                else{
                    dist[i][j] = min(val, dist[i-1][j-1] + 1);
                }
            }
        }
        
        return dist[len1][len2];
    }
};
