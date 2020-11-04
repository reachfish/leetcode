/*
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle
 *
 * Easy (35.42%)
 * Total Accepted:    179129
 * Total Submissions: 505743
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, determine if it has a cycle in it.
 * 
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        if(!head||!(head->next)){
            return false;
        }
        
        ListNode *p = head, *q = head;
        do{
            p = p->next;
            q = q->next->next;
        }while(q && q->next && (p!=q));
        
        return p == q;
    }
};
