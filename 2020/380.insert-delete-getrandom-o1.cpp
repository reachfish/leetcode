/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 *
 * https://leetcode.com/problems/insert-delete-getrandom-o1/description/
 *
 * algorithms
 * Medium (49.19%)
 * Likes:    3553
 * Dislikes: 207
 * Total Accepted:    334.6K
 * Total Submissions: 679.7K
 * Testcase Example:
 '["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"]\n'
 +
  '[[],[1],[2],[2],[],[1],[2],[]]'
 *
 * Implement the RandomizedSet class:
 *
 *
 * RandomizedSet() Initializes the RandomizedSet object.
 * bool insert(int val) Inserts an item val into the set if not present.
 * Returns true if the item was not present, false otherwise.
 * bool remove(int val) Removes an item val from the set if present. Returns
 * true if the item was present, false otherwise.
 * int getRandom() Returns a random element from the current set of elements
 * (it's guaranteed that at least one element exists when this method is
 * called). Each element must have the same probability of being returned.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove",
 * "insert", "getRandom"]
 * [[], [1], [2], [2], [], [1], [2], []]
 * Output
 * [null, true, false, true, 2, true, false, 2]
 *
 * Explanation
 * RandomizedSet randomizedSet = new RandomizedSet();
 * randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was
 * inserted successfully.
 * randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
 * randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now
 * contains [1,2].
 * randomizedSet.getRandom(); // getRandom() should return either 1 or 2
 * randomly.
 * randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now
 * contains [2].
 * randomizedSet.insert(2); // 2 was already in the set, so return false.
 * randomizedSet.getRandom(); // Since 2 is the only number in the set,
 * getRandom() will always return 2.
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= val <= 2^31 - 1
 * At most 10^5 calls will be made to insert, remove, and getRandom.
 * There will be at least one element in the data structure when getRandom is
 * called.
 *
 *
 *
 * Follow up: Could you implement the functions of the class with each function
 * works in average O(1) time?
 */

// @lc code=start
class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (index_.count(val)) {
      return false;
    }

    index_[val] = value_.size();
    value_.push_back(val);

    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    auto it = index_.find(val);
    if (it == index_.end()) {
      return false;
    }

    int pos = it->second;
    value_[pos] = value_.back();
    index_[value_.back()] = pos;
    value_.pop_back();
    index_.erase(val);

    return true;
  }

  /** Get a random element from the set. */
  int getRandom() { return value_[rand() % value_.size()]; }

 private:
  map<int, int> index_;
  vector<int> value_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
