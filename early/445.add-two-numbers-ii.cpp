/*
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii
 *
 * Medium (45.98%)
 * Total Accepted:    22174
 * Total Submissions: 48221
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 * 
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
    int getLen(ListNode* p){
        int c = 0;
        while(p){
            c++;
            p = p->next;
        }
        
        return c;
    }
    
    void addTwo(ListNode *p, ListNode *q, int &flag){
        if(!p) return;
        
        addTwo(p->next, q->next, flag);
        
        int val = p->val + q->val + flag;
        if(val >= 10){
            val -= 10;
            flag = 1;
        }
        else{
            flag = 0;
        }
        
        p->val = val;
    }
    
    void addSigle(ListNode*p, ListNode* end, int &flag){
        if(p==end) return;
        addSigle(p->next, end, flag);
        
        int val = p->val + flag;
        if(val >= 10){
            val -= 10;
            flag = 1;
        }
        else{
            flag = 0;
        }
        p->val = val;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c1 = getLen(l1);
        int c2 = getLen(l2);
        
        if(c1==0) return l2;
        if(c2==0) return l1;
        
        ListNode *lList, *sList;
        if(c1>=c2){
            lList = l1;
            sList = l2;
        }
        else{
            lList = l2;
            sList = l1;
        }
        
        ListNode *m = lList;
        for(int i=0;i<abs(c1-c2);i++){
            m = m->next;
        }
        
        int flag = 0;
        
        addTwo(m, sList, flag);
        addSigle(lList, m, flag);
        
        if(flag){
            ListNode *p = new ListNode(1);
            p->next = lList;
            lList = p;
        }
        
        return lList;
    }
};
