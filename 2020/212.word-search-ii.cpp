/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (36.69%)
 * Likes:    3557
 * Dislikes: 142
 * Total Accepted:    289.1K
 * Total Submissions: 774K
 * Testcase Example:
 '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * Given an m x n board of characters and a list of strings words, return all
 * words on the board.
 *
 * Each word must be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once in a word.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
 * words = ["oath","pea","eat","rain"]
 * Output: ["eat","oath"]
 *
 *
 * Example 2:
 *
 *
 * Input: board = [["a","b"],["c","d"]], words = ["abcb"]
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 12
 * board[i][j] is a lowercase English letter.
 * 1 <= words.length <= 3 * 10^4
 * 1 <= words[i].length <= 10
 * words[i] consists of lowercase English letters.
 * All the strings of words are unique.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  struct Node {
    bool tail = false;
    map<char, unique_ptr<Node>> branch;
  };

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int m = board.size();
    int n = board.empty() ? 0 : board.front().size();
    if (m == 0 || n == 0 || words.empty()) {
      return {};
    }

    Node root;
    for (const auto& w : words) {
      Node* p = &root;
      for (auto c : w) {
        auto it = p->branch.find(c);
        if (it == p->branch.end()) {
          it = p->branch.insert(make_pair(c, unique_ptr<Node>(new Node))).first;
        }
        p = it->second.get();
      }
      p->tail = true;
    }

    vector<vector<bool>> flags(m, vector<bool>(n, false));
    set<string> result;
    int k = 1;
    string word;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        word.clear();
        k++;
        flags[i][j] = true;
        dp(board, k, root, flags, word, i, j, result);
        flags[i][j] = false;
      }
    }

    return {result.begin(), result.end()};
  }

  void dp(const vector<vector<char>>& board, int k, const Node& p,
          vector<vector<bool>>& flags, string& word, int i, int j,
          set<string>& result) {
    char c = board[i][j];
    auto it = p.branch.find(c);
    if (it == p.branch.end()) {
      return;
    }

    word.push_back(c);
    const Node& next = *(it->second.get());
    if (next.tail) {
      result.insert(word);
    }

    if (next.branch.empty()) {
      return;
    }

    int m = board.size();
    int n = board[0].size();
    size_t sz = word.size();
    const static int kDir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (const auto& dir : kDir) {
      int ni = i + dir[0];
      int nj = j + dir[1];
      if (ni < 0 || ni >= m || nj < 0 || nj >= n || flags[ni][nj]) {
        continue;
      }

      word.resize(sz);
      flags[ni][nj] = true;
      dp(board, k, next, flags, word, ni, nj, result);
      flags[ni][nj] = false;
    }
  }
};
// @lc code=end
