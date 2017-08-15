/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists
 *
 * algorithms
 * Easy (39.00%)
 * Total Accepted:    242.3K
 * Total Submissions: 620.8K
 * Testcase Example:  '[]\n[]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode *head = nullptr; 
	   ListNode *cur = nullptr;
	   while(l1 && l2){
		   ListNode *p = l1->val <= l2->val ? l1 : l2;
		   if(cur){
			   cur->next = p;
			   cur = p;
		   }
		   else{
			   head = cur = p;
		   }

		   if(p==l1){
			   l1 = l1->next;
		   }
		   else{
			   l2 = l2->next;
		   }

		   cur->next = nullptr;
	   }

	   if(l1 || l2){
		   ListNode* p = l1 ? l1 : l2;
		   if(cur){
			   cur->next = p;
			   cur = p;
		   }
		   else{
			   head = cur = p;
		   }
	   }

	   return head;
    }
};
