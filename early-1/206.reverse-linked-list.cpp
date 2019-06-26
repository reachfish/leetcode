/*
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list
 *
 * Easy (44.95%)
 * Total Accepted:    226502
 * Total Submissions: 503852
 * Testcase Example:  '[]'
 *
 * Reverse a singly linked list.
 * 
 * click to show more hints.
 * 
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
 * 
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
    ListNode* reverseList(ListNode* head) {
        if(!head) { return head; }
        ListNode *p = head;
        ListNode *pre = NULL;
        while(true){
            ListNode *next = p->next;
            p->next = pre;
            if(next) { pre = p; p = next; }
            else {  return p; }
        }
    }
};
