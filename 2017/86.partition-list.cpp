/*
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list
 *
 * Medium (32.29%)
 * Total Accepted:    97778
 * Total Submissions: 302854
 * Testcase Example:  '[]\n0'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * 
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        if(!head){
            return head;
        }
        
        ListNode *small = NULL, *big = NULL, *shead = NULL, *bhead = NULL;
        for(ListNode *p=head;p;){
            ListNode *next = p->next;
            if(p->val < x){
                if(small){
                    small->next = p;
                }
                else{
                    shead = p;
                }
                small = p;
            }
            else{
                if(big){
                    big->next = p;
                }
                else{
                    bhead = p;
                }
                big = p;
            }
            
            p = next;
        }
        
        if(small){
            small->next = bhead;
        }
        if(big){
            big->next = NULL;
        }
        
        return shead ? shead : bhead;
    }
};
