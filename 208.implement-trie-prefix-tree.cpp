/*
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree
 *
 * Medium (27.44%)
 * Total Accepted:    74196
 * Total Submissions: 270390
 * Testcase Example:  '["Trie","search"]\n[[],["a"]]'
 *
 * 
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * 
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * 
 */
class Trie {
private:
    typedef struct node{
        map<char, node*> childs;
        bool isWord;
        node() : isWord(false) {} 
    }node;

    node root;

    node *findNode(string word){
        node *t = &root;
        for(auto c : word){
            if(!t->childs.count(c)) { return NULL; }
            t = t->childs[c];
        } 

        return t;
    }

public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node *t = &root;
        for(auto c : word){
            if(!t->childs.count(c)) { t->childs[c] = new node; }
            t = t->childs[c];
        }

        t->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node *t = findNode(word);

        return t && t->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return findNode(prefix) != NULL;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
