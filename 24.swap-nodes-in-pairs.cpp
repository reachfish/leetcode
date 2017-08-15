/*
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs
 *
 * algorithms
 * Medium (38.27%)
 * Total Accepted:    171.3K
 * Total Submissions: 447.4K
 * Testcase Example:  '[]'
 *
 * 
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * 
 * 
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 * 
 * Your algorithm should use only constant space. You may not modify the values
 * in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
		ListNode *pre = nullptr;        
		ListNode *p = head, *q = nullptr, *next = nullptr;

		while(p && p->next){
			q = p->next;
			next = q->next;
			if(pre){
				pre->next = q;
			}
			else{
				head = q;
			}

			q->next = pre = p;
			p->next = next;

			p = p->next;
		}

		return head;
    }
};
