/*
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii
 *
 * Hard (23.03%)
 * Total Accepted:    43917
 * Total Submissions: 190659
 * Testcase Example:  '["oaan","etae","ihkr","iflv"]\n["oath","pea","eat","rain"]'
 *
 * 
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 * 
 * 
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 * 
 * 
 * 
 * For example,
 * Given words = ["oath","pea","eat","rain"] and board = 
 * 
 * [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * 
 * 
 * Return ["eat","oath"].
 * 
 * 
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * 
 * 
 * click to show hint.
 * 
 * You would need to optimize your backtracking to pass the larger test. Could
 * you stop backtracking earlier?
 * 
 * If the current candidate does not exist in all words' prefix, you could stop
 * backtracking immediately. What kind of data structure could answer such
 * query efficiently? Does a hash table work? Why or why not? How about a Trie?
 * If you would like to learn how to implement a basic trie, please work on
 * this problem: Implement Trie (Prefix Tree) first.
 * 
 */

int dirs[][2] = { {1,0}, {-1,0}, {0,1}, {0, -1} };

class Solution {
public:
	typedef struct trie{
		map<char, trie*> childs;
		bool isWord;

		trie():isWord(false){}
	}trie;

	trie* buildTrie(const vector<string>& words){
		trie *root = new trie();
		for(auto word : words){
			trie* p = root;
			for(auto c : word){
				if(!p->childs.count(c)){
					p->childs[c] = new trie();
				}

				p = p->childs[c];
			}

			p->isWord = true;
		}

		return root;
	}

	void dfs(trie* p, vector<vector<char>>& board, int i, int j, string& s, vector<string>& res){
		int m = board.size();
		int n = board[0].size();

		if(i<0||i>=m||j<0||j>=n||board[i][j]=='#'||!p||!p->childs.count(board[i][j])){
			return;
		}

		char c = board[i][j]; 
		board[i][j] = '#';
		s.push_back(c);

		p = p->childs[c];
		if(p->isWord){
			res.push_back(s);
			p->isWord = false;
		}

		for(int k = 0; k < 4; k++){
			dfs(p, board, i + dirs[k][0], j + dirs[k][1], s, res);
		}

		s.pop_back();
		board[i][j] = c;
	}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		if(board.empty()||board[0].empty()||words.empty()) { return vector<string>(); }

		vector<string> res;

		trie* root = buildTrie(words);

		string s;

		int m = board.size();
		int n = board[0].size();
		for(int i=0; i< m; i++){
			for(int j=0; j<n; j++){
				dfs(root, board, i, j, s, res);
			}
		}

		return res;
    }
};
