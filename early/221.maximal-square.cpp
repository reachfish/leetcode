/*
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square
 *
 * Medium (28.31%)
 * Total Accepted:    59940
 * Total Submissions: 211727
 * Testcase Example:  '["10100","10111","11111","10010"]'
 *
 * 
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * 
 * For example, given the following matrix:
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Return 4.
 * 
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    typedef struct{
        int left;
        int up;
        int sq;
    }TCal;
    
    int min(int a, int b){
        return a < b ? a : b;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty()){
            return 0;
        }
        
        size_t rows = matrix.size();
        size_t cols = matrix[0].size();
        TCal count[2][cols];
        
        int max = 0;
        int left = 0;
        for(int i=0;i<cols;i++){
            TCal &cal = count[0][i];
            if(matrix[0][i]=='0'){
                cal.left = 0;
                cal.up = 0;
                cal.sq = 0;
            }
            else{
                cal.left = 1;
                cal.up = 1;
                cal.sq = 1;
                if(i){
                    cal.left += count[0][i-1].left;
                }
                
                max = 1;
            }
        }
        
        int cur = 1;
        for(int i=1;i<rows;i++){
            int last = 1 - cur; 
            for(int j=0;j<cols;j++){
                TCal &cal = count[cur][j];
                if(matrix[i][j]=='0'){
                    cal.left = 0;
                    cal.up = 0;
                    cal.sq = 0;
                }
                else{
                    cal.left = j ? count[cur][j-1].left + 1 : 1;
                    cal.up = count[last][j].up + 1;
                    cal.sq = j ? min(count[last][j-1].sq, min(count[cur][j-1].left, count[last][j].up)) + 1: 1;
                    int sq = cal.sq * cal.sq;
                    max = max > sq ? max : sq;
                }
            }
            cur = 1 - cur;
        }
        
        return max;
    }
};
