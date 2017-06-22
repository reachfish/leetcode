/*
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions
 *
 * Medium (18.13%)
 * Total Accepted:    80437
 * Total Submissions: 443579
 * Testcase Example:  '["XXXX","XOOX","XXOX","XOXX"]'
 *
 * 
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * 
 * 
 * For example,
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 
 * 
 * After running your function, the board should be:
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 */
class Solution {
public:
    void changeZero(vector<vector<char>> &board, int i, int j, queue<pair<int, int>> & que){
        if(i<0 || i>= board.size() || j<0 || j>=board[0].size() || board[i][j]!='O') return;
        
        board[i][j] = 'Y';
        que.push(make_pair(i,j));
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.empty()||board[0].empty()) { return ; }
        
        int m = board.size();
        int n = board[0].size();
        
        queue<pair<int, int> > que;
        for(int i=0;i<m;i++){
            changeZero(board, i, 0, que);
            changeZero(board, i, n-1, que);
        }
        for(int j=0;j<n;j++){
            changeZero(board, 0, j, que);
            changeZero(board, m-1, j, que);
        }
        
        int dirs[][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!que.empty()){
            pair<int, int> p = que.front();
            que.pop();
            for(int k=0;k<4;k++){
                changeZero(board, p.first + dirs[k][0], p.second + dirs[k][1], que);
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j] = 'X';
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='Y') board[i][j] = 'O';
            }
        }
    }
};
