/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list
 *
 * Easy (32.40%)
 * Total Accepted:    103597
 * Total Submissions: 319688
 * Testcase Example:  '[]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool compareNode(ListNode* &p, ListNode* q){
        if(!q) { return true; }
        
        if(!compareNode(p, q->next)) { return false; }
        
        if(p->val != q->val) { return false; }
        
        p = p->next;
        
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* p = head;
        
        return compareNode(p, head);
    }
};
