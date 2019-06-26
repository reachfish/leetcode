/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists
 *
 * algorithms
 * Hard (27.15%)
 * Total Accepted:    158.6K
 * Total Submissions: 583.7K
 * Testcase Example:  '[]'
 *
 * 
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
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
	struct cmp{
		bool operator()(ListNode* l, ListNode* r){
			return l->val > r->val;
		}
	};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> que;
		for(auto list : lists){
			if(list){
				que.push(list);
			}
		}

		ListNode* head = nullptr;
		ListNode* cur = nullptr;

		while(!que.empty()){
			ListNode* p = que.top();
			que.pop();
			if(cur){
				cur->next = p;
				cur = p;
			}
			else{
				head = cur = p;
			}

			p = p->next;
			cur->next = nullptr;

			if(p){
				que.push(p);
			}
		}

		return head;
    }
};
