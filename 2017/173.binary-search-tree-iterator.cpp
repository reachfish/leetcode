/*
 * [173] Binary Search Tree Iterator
 *
 * https://leetcode.com/problems/binary-search-tree-iterator
 *
 * Medium (40.69%)
 * Total Accepted:    88845
 * Total Submissions: 218320
 * Testcase Example:  '[]'
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST.
 * 
 * Calling next() will return the next smallest number in the BST.
 * 
 * Note: next() and hasNext() should run in average O(1) time and uses O(h)
 * memory, where h is the height of the tree. 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        p = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        while(p){
            stk.push(p);
            p = p->left;
        }
        
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *q = stk.top();
        stk.pop();
        
        p = q->right;
        
        return q->val;
    }
    
    
private:
    stack<TreeNode* > stk;
    TreeNode *p;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
