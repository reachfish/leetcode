/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (51.70%)
 * Likes:    4353
 * Dislikes: 69
 * Total Accepted:    402.4K
 * Total Submissions: 767.5K
 * Testcase Example:
 '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are
 * various applications of this data structure, such as autocomplete and
 * spellchecker.
 *
 * Implement the Trie class:
 *
 *
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie
 * (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously
 * inserted string word that has the prefix prefix, and false otherwise.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 * [null, null, true, false, true, null, true]
 *
 * Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length, prefix.length <= 2000
 * word and prefix consist only of lowercase English letters.
 * At most 3 * 10^4 calls in total will be made to insert, search, and
 * startsWith.
 *
 *
 */

// @lc code=start
class Trie {
 public:
  struct Node {
    bool tail = false;
    map<char, unique_ptr<Node>> children;
  };

  /** Initialize your data structure here. */
  Trie() {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    Node* p = &root;
    for (auto c : word) {
      auto& children = p->children;
      auto it = children.find(c);
      if (it == children.end()) {
        it = children.insert(make_pair(c, unique_ptr<Node>(new Node))).first;
      }

      p = it->second.get();
    }

    p->tail = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    auto n = searchPrefix(word);
    return n != nullptr && n->tail == true;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) { return searchPrefix(prefix) != nullptr; }

 private:
  Node* searchPrefix(const std::string& prefix) {
    Node* p = &root;
    for (auto c : prefix) {
      auto& children = p->children;
      auto it = children.find(c);
      if (it == children.end()) {
        return nullptr;
      }

      p = it->second.get();
    }

    return p;
  }

 private:
  Node root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
