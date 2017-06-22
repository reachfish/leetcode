/*
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists
 *
 * Easy (30.45%)
 * Total Accepted:    130200
 * Total Submissions: 427613
 * Testcase Example:  'No intersection: []\n[]'
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 * 
 * For example, the following two linked lists: 
 * 
 * A:          a1 → a2
 * ⁠                  ↘
 * ⁠                    c1 → c2 → c3
 * ⁠                  ↗            
 * B:     b1 → b2 → b3
 * 
 * begin to intersect at node c1.
 * 
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns. 
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * 
 * 
 * 
 * Credits:Special thanks to @stellari for adding this problem and creating all
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
    int getLen(ListNode *p){
        int count = 0;
        while(p){
            count++;
            p = p->next;
        }
        
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB){
            return NULL;
        }
        
        int len1 = getLen(headA);
        int len2 = getLen(headB);
        
        if(len1>len2){
            for(int i=len1-len2;i>0;i--){
                headA = headA->next;
            }
        }
        else{
            for(int i=len2-len1;i>0;i--){
                headB = headB->next;
            }
        }
        
        while(headA && headB){
            if(headA==headB){
                return headA;
            }
            
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};
