/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers
 *
 * algorithms
 * Medium (27.68%)
 * Total Accepted:    327.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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

	int addValue(int val1, int val2, int &flag){
		int val = val1 + val2 + flag;
		if(val >= 10){
			val -= 10;
			flag = 1;
		}
		else{
			flag = 0;
		}

		return val;
	}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int flag = 0; 
	   ListNode *head = nullptr;
	   ListNode *pre = nullptr;

	   while(l1 || l2 || flag){
		   int val1 = 0;
		   int val2 = 0;
		   if(l1){
			   val1 = l1->val;
			   l1 = l1->next;
		   }
		   if(l2){
			   val2 = l2->val;
			   l2 = l2->next;
		   }

		   ListNode *p = new struct ListNode(addValue(val1, val2, flag));
		   if(!pre){
			   head = pre = p;
		   }
		   else{
			   pre->next = p;
			   pre = p;
		   }
	   }

	   return head;
    }
};
