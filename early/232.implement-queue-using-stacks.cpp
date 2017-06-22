/*
 * [232] Implement Queue using Stacks
 *
 * https://leetcode.com/problems/implement-queue-using-stacks
 *
 * Easy (36.22%)
 * Total Accepted:    80582
 * Total Submissions: 222479
 * Testcase Example:  '["MyQueue","empty"]\n[[],[]]'
 *
 * 
 * Implement the following operations of a queue using stacks.
 * 
 * 
 * push(x) -- Push element x to the back of queue.
 * 
 * 
 * pop() -- Removes the element from in front of queue.
 * 
 * 
 * peek() -- Get the front element.
 * 
 * 
 * empty() -- Return whether the queue is empty.
 * 
 * 
 * Notes:
 * 
 * You must use only standard operations of a stack -- which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may
 * simulate a stack by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek
 * operations will be called on an empty queue).
 * 
 * 
 */
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        shift();
        int val = s2.top();
        s2.pop();
        
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        shift();
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
    
    void shift(){
        if(!s2.empty()){
            return;
        }
        
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
