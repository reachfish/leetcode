/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists
 *
 * Hard (26.85%)
 * Total Accepted:    147991
 * Total Submissions: 551100
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
    static bool compare(ListNode* a, ListNode* b){
        return a->val >= b->val;    
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> v;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                v.push_back(lists[i]);
            }
        }
        
        ListNode *head = NULL;
        ListNode *p = NULL;
        
        make_heap(v.begin(), v.end(), Solution::compare);
        
        while(!v.empty()){
            ListNode *q = v.front();
            pop_heap(v.begin(), v.end(), compare);
            v.pop_back();
            
            if(p){
                p->next = q;
            }
            else{
                head = q;
            }
            
            p = q;
            
            if(q->next){
                v.push_back(q->next);
                push_heap(v.begin(), v.end(), compare);
            }
        }
        
        return head;
    }
};
