/*
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
 *
 * Medium (29.21%)
 * Total Accepted:    107338
 * Total Submissions: 367470
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * 
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
            return NULL;
        }
        
        ListNode *pre = NULL;
        ListNode *p = head;
        while(p){
            ListNode *q = p;
            while(q&&q->val==p->val){
                q = q->next;
            }
            
            if(p->next==q){
                pre = p;
                p = p->next;
            }
            else{
                if(pre){
                    pre->next = q;
                }
                if(head==p){
                    head = q;
                }
                
                while(p!=q){
                    ListNode *next = p->next;
                    delete p;
                    p = next;
                }
            }
        }
        
        return head;
    }
};
