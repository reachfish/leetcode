/*
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer
 *
 * Medium (26.39%)
 * Total Accepted:    112019
 * Total Submissions: 424476
 * Testcase Example:  '{}'
 *
 * 
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * 
 * 
 * Return a deep copy of the list.
 * 
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    void copyList(RandomListNode *head){
        RandomListNode* p = head;
        while(p){
            RandomListNode *q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
    }

    void addRandomPoint(RandomListNode* head){
        RandomListNode* p = head;
        while(p){
            RandomListNode *q = p->next;
            if(p->random){
                q->random = p->random->next;
            }
            p = q->next;
        }
    }

    void splitList(RandomListNode* head){
        RandomListNode *p = head;
        while(p){
            RandomListNode *q = p->next;
            p->next = q->next;
            p = p->next;
            q->next = p ? p->next :NULL;
        }
    }

    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) { return NULL; }
        copyList(head);        
        addRandomPoint(head);

        RandomListNode* h = head->next;
        splitList(head);

        return h;
    }
};

