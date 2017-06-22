/*
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree
 *
 * Medium (33.60%)
 * Total Accepted:    104678
 * Total Submissions: 311529
 * Testcase Example:  '[]'
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, NULL);
    }
    
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
        if(head==tail){
            return NULL;
        }
        
        ListNode *p = head;
        ListNode *q = head;
        
        while(q!=tail){
            q = q->next;
            if(q==tail) { break; }
            q = q->next;
            p = p->next;
        }
        
        TreeNode *root = new TreeNode(p->val);
        root->left = sortedListToBST(head, p);
        root->right = sortedListToBST(p->next, tail);
        
        return root;
    }
};
