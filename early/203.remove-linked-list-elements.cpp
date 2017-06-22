/*
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements
 *
 * Easy (32.02%)
 * Total Accepted:    113529
 * Total Submissions: 354584
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6,  val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 * 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){
            return head;
        }
        
        ListNode *pre = NULL, *next = NULL;
        ListNode *p = head;
        while(p){
            next = p->next;
            if(p->val == val){
                if(pre){
                    pre->next = next;
                }
                
                delete p;
            }
            else{
                if(!pre){
                    head = p;
                }
                
                pre = p;
            }
            
            p = next;
        }
        
        if(!pre){
            return NULL;
        }
        
        return head;
    }
};
