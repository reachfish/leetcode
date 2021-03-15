/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (46.13%)
 * Likes:    4726
 * Dislikes: 438
 * Total Accepted:    690.6K
 * Total Submissions: 1.5M
 * Testcase Example:
 '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 *
 * Output
 * [null,null,null,null,-3,null,0,-2]
 *
 * Explanation
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin(); // return -3
 * minStack.pop();
 * minStack.top();    // return 0
 * minStack.getMin(); // return -2
 *
 *
 *
 * Constraints:
 *
 *
 * Methods pop, top and getMin operations will always be called on non-empty
 * stacks.
 *
 *
 */

// @lc code=start
class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    elems_.push_back(x);
    min_.push_back(min_.empty() ? x : std::min(x, min_.back()));
  }

  void pop() {
    elems_.pop_back();
    min_.pop_back();
  }

  int top() { return elems_.back(); }

  int getMin() { return min_.back(); }

 private:
  vector<int> elems_;
  vector<int> min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
