/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search
 *
 * Medium (26.28%)
 * Total Accepted:    123730
 * Total Submissions: 470734
 * Testcase Example:  '["ABCE","SFCS","ADEE"]\n"ABCCED"'
 *
 * 
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * 
 * 
 * For example,
 * Given board = 
 * 
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 * 
 */
class Solution {
public:
    bool helper(const vector<vector<char>>& board, int i, int j, const string& word, int k, vector<vector<int>>& flag){
        if(k==word.size()) { return true; }
        if(i<0 || i>=board.size() || j<0 || j>= board[0].size() || board[i][j] != word[k] || flag[i][j]) { return false; }
        flag[i][j] = 1;
        
        int dirs[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(int r=0;r<4;r++){
            if(helper(board, i+dirs[r][0], j+dirs[r][1], word, k+1, flag)) { return true; }
        }
        
        flag[i][j] = 0;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()||board[0].empty()||word.empty()) { return false; }
        
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> flag(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(helper(board, i, j, word, 0,flag)) { return true; }                
            }
        }
        
        return false;
    }
};
