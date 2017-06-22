/*
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii
 *
 * Medium (31.01%)
 * Total Accepted:    113321
 * Total Submissions: 365444
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * 
 * 
 * Note: Do not modify the linked list.
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
    int getMeet(ListNode *&p, ListNode *&q){
        int count = 0;
        while(q && q->next && (!count || q!=p)){
            p = p->next;
            q = q->next->next;
            count++;
        }
        
        return p == q ? count : 0;
    }
    
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        if(getMeet(p, q)==0){
            return NULL;
        }
        
        int n = getMeet(p, q);
        p = q = head;
        for(int i=1;i<=n;i++){
            q = q->next;
        }
        
        while(p!=q){
            p = p->next;
            q = q->next;
        }
        
        return p;
    }
};
