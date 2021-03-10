/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (35.40%)
 * Likes:    7954
 * Dislikes: 326
 * Total Accepted:    719K
 * Total Submissions: 2M
 * Testcase Example:
 '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design a data structure that follows the constraints of a Least Recently
 * Used (LRU) cache.
 *
 * Implement the LRUCache class:
 *
 *
 * LRUCache(int capacity) Initialize the LRU cache with positive size
 * capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise
 * return -1.
 * void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys
 * exceeds the capacity from this operation, evict the least recently used
 * key.
 *
 *
 * Follow up:
 * Could you do get and put in O(1) time complexity?
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= capacity <= 3000
 * 0 <= key <= 3000
 * 0 <= value <= 10^4
 * At most 3 * 10^4 calls will be made to get and put.
 *
 *
 */

// @lc code=start
class LRUCache {
 public:
  LRUCache(int capacity) { capacity_ = capacity; }

  int get(int key) {
    auto it = it_.find(key);
    if (it == it_.end()) {
      return -1;
    }

    auto itv = it->second;
    auto v = itv->v;
    kv_.splice(kv_.end(), kv_, itv);

    return v;
  }

  void put(int key, int value) {
    auto it = it_.find(key);
    if (it != it_.end()) {
      auto itv = it->second;
      itv->v = value;
      kv_.splice(kv_.end(), kv_, itv);
    } else {
      if (it_.size() >= capacity_) {
        it_.erase(kv_.begin()->k);
        kv_.pop_front();
      }
      kv_.push_back({key, value});
    }

    auto itv = kv_.end();
    it_[key] = --itv;
  }

 private:
  struct KV {
    int k;
    int v;
  };

  unordered_map<int, list<KV>::iterator> it_;
  list<KV> kv_;
  int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
