/*
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design
 *
 * Medium (22.02%)
 * Total Accepted:    52705
 * Total Submissions: 239385
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * 
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one
 * letter.
 * 
 * 
 * For example:
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * 
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 * 
 * 
 * click to show hint.
 * 
 * You should be familiar with how a Trie works. If not, please work on this
 * problem: Implement Trie (Prefix Tree) first.
 * 
 */
class WordDictionary {
private: 
    struct node{
        bool leaf;
        map<char, node*> childs;
        node(){leaf=false;}
    };
    
    node *root;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        node *cur = root;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(!(cur->childs.count(c))){
                cur->childs[c] = new node;
            }
            cur = cur->childs[c];
        }
        cur->leaf = true;
    }
    
    bool searchSub(node* cur, const string &word, int i){
        if(i==word.size()){
            return cur->leaf;
        }
        
        char c = word[i];
        if(c!='.'){
            if(!cur->childs.count(c)){
                return false;
            }
            
            return searchSub(cur->childs[c], word, i+1);
        }
        else{
            for(auto it=cur->childs.begin();it!=cur->childs.end();it++){
                if(searchSub(it->second, word, i+1)){
                    return true;
                }
            }
            
            return false;
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchSub(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
