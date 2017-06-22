/*
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list
 *
 * Easy (39.60%)
 * Total Accepted:    180712
 * Total Submissions: 456334
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return head;
        }
        
        ListNode *p = head, *q = p->next;
        while(q){
            if(p->val==q->val){
                ListNode *tmp = q->next;
                p->next = q->next;
                delete q;
                q = tmp;
            }
            else{
                p = p->next;
                q = q->next;
            }
        }
        
        return head;
    }
};
