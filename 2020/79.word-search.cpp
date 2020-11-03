/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (36.12%)
 * Likes:    4639
 * Dislikes: 209
 * Total Accepted:    555.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cells,
 * where "adjacent" cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board and word consists only of lowercase and uppercase English letters.
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) {
            return false;
        }
        int m = board.size();
        if (m == 0) {
            return false;
        }
        int n = board[0].size();
        if (n == 0) {
            return false;
        }

        vector<vector<bool>> flag(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (helper(board, flag, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool helper(const vector<vector<char>>& board,
                vector<vector<bool>>& flag,
                int i,
                int j,
                const std::string& word,
                int k) {
        if (k == word.size()) {
            return true;
        }

        int m = flag.size();
        int n = flag[0].size();
        if (i == m || i == -1 || j == n || j == -1 || board[i][j] != word[k] || flag[i][j]) {
            return false;
        }

        flag[i][j] = true;

        const int d[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto pr : d) {
            if (helper(board, flag, i + pr[0], j + pr[1], word, k + 1)) {
                return true;
            }
        }

        flag[i][j] = false;
        return false;
    }
};
// @lc code=end
