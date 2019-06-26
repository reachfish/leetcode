/*
 * [116] Populating Next Right Pointers in Each Node
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node
 *
 * Medium (36.96%)
 * Total Accepted:    131386
 * Total Submissions: 355503
 * Testcase Example:  '{}'
 *
 * 
 * Given a binary tree
 * 
 * ⁠   struct TreeLinkNode {
 * ⁠     TreeLinkNode *left;
 * ⁠     TreeLinkNode *right;
 * ⁠     TreeLinkNode *next;
 * ⁠   }
 * 
 * 
 * 
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 * 
 * 
 * Note:
 * 
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the
 * same level, and every parent has two children).
 * 
 * 
 * 
 * 
 * For example,
 * Given the following perfect binary tree,
 * 
 * ⁠        1
 * ⁠      /  \
 * ⁠     2    3
 * ⁠    / \  / \
 * ⁠   4  5  6  7
 * 
 * 
 * 
 * After calling your function, the tree should look like:
 * 
 * ⁠        1 -> NULL
 * ⁠      /  \
 * ⁠     2 -> 3 -> NULL
 * ⁠    / \  / \
 * ⁠   4->5->6->7 -> NULL
 * 
 * 
 */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root){
            return;
        }
        
        queue<TreeLinkNode* > que;
        que.push(root);
        que.push(NULL);
        
        TreeLinkNode *pre = NULL;
        while(!que.empty()){
            TreeLinkNode *node = que.front();
            que.pop();
            
            if(node){
                if(pre){
                    pre->next = node;
                }
                
                if(node->left){
                    que.push(node->left);
                }
                
                if(node->right){
                    que.push(node->right);
                }
            }
            else if(!que.empty()){
                que.push(NULL);
            }
            
            pre = node;
        }
    }
};
