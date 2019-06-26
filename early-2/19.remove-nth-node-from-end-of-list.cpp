/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list
 *
 * algorithms
 * Medium (33.41%)
 * Total Accepted:    187.5K
 * Total Submissions: 560.6K
 * Testcase Example:  '[1]\n1'
 *
 * Given a linked list, remove the nth node from the end of list and return its
 * head.
 * 
 * 
 * For example,
 * 
 * 
 * ⁠  Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * ⁠  After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * 
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		if(head == nullptr || n<=0){
			return head;
		}

		ListNode *fast = head;
		for(int i=1; i<n; i++){
			fast = fast->next;
			if(fast==nullptr){
				break;
			}
		}

		if(fast == nullptr){
			return head;
		}

		ListNode *pre = nullptr;
		ListNode *slow = head;
		while(fast->next){
			pre = slow;
			slow = slow->next;
			fast = fast->next;
		}

		if(pre){
			pre->next = slow->next;
		}
		else{
			head = slow->next;
		}

		delete slow;

		return head;
    }
};
