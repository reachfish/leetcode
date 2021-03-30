/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 *
 * https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
 *
 * algorithms
 * Medium (39.92%)
 * Likes:    2844
 * Dislikes: 122
 * Total Accepted:    275.1K
 * Total Submissions: 679.6K
 * Testcase Example:
 '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n'
 +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports adding new words and finding if a
 * string matches any previously added string.
 *
 * Implement the WordDictionary class:
 *
 *
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched
 * later.
 * bool search(word) Returns true if there is any string in the data structure
 * that matches word or false otherwise. word may contain dots '.' where dots
 * can be matched with any letter.
 *
 *
 *
 * Example:
 *
 *
 * Input
 *
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * Output
 * [null,null,null,null,false,true,true,true]
 *
 * Explanation
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // return False
 * wordDictionary.search("bad"); // return True
 * wordDictionary.search(".ad"); // return True
 * wordDictionary.search("b.."); // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length <= 500
 * word in addWord consists lower-case English letters.
 * word in search consist of  '.' or lower-case English letters.
 * At most 50000 calls will be made to addWord and search.
 *
 *
 */

// @lc code=start
class WordDictionary {
 public:
  struct Node {
    bool tail = false;
    Node* branches[26];

    void destroy() {
      for (auto& b : branches) {
        if (b) {
          b->destroy();
          delete b;
          b = nullptr;
        }
      }
    }

    Node() { memset(branches, 0, sizeof(branches)); }
  };

  /** Initialize your data structure here. */
  WordDictionary() {}

  ~WordDictionary() { root.destroy(); }

  void addWord(string word) {
    Node* p = &root;
    for (auto c : word) {
      Node*& b = p->branches[c - 'a'];
      if (b == nullptr) {
        b = new Node;
      }
      p = b;
    }

    p->tail = true;
  }

  bool search(string word) { return searchFrom(word.c_str(), &root); }

  bool searchFrom(const char* c, const Node* p) {
    char ch = *c;
    if (ch == '\0') {
      return p != nullptr && p->tail;
    }

    if (p == nullptr) {
      return false;
    }

    const auto& branches = p->branches;
    int index = ch - 'a';
    if (ch == '.') {
      for (int i = 0; i < 26; i++) {
        const Node* b = branches[i];
        if (b != nullptr && searchFrom(c + 1, b)) {
          return true;
        }
      }
      return false;
    } else {
      const Node* b = branches[index];
      if (b == nullptr) {
        return false;
      }
      return searchFrom(c + 1, b);
    }
  }

 private:
  Node root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
