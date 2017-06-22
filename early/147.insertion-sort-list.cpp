/*
 * [147] Insertion Sort List
 *
 * https://leetcode.com/problems/insertion-sort-list
 *
 * Medium (32.72%)
 * Total Accepted:    100257
 * Total Submissions: 306377
 * Testcase Example:  '[]'
 *
 * Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head){
            return NULL;
        }
        
        ListNode *p = head->next;
        while(p){
            ListNode *next = p->next;
            ListNode *q = head, *pre = NULL;
            while(q!=p&&q->val <= p->val){
                pre = q;
                q = q->next;
            }
            if(q!=p){
                p->next = q;
                while(q->next!=p){
                    q = q->next;
                }
                q->next = next;
                if(pre){
                    pre->next = p;
                }
                else{
                    head = p;
                }
            }
            
            p = next;
        }
        
        return head;
    }
};
