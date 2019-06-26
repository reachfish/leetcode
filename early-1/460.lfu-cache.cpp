/*
 * [460] LFU Cache
 *
 * https://leetcode.com/problems/lfu-cache
 *
 * Hard (22.91%)
 * Total Accepted:    10592
 * Total Submissions: 46233
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Frequently Used (LFU) cache.
 * It should support the following operations: get and put.
 * 
 * 
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reaches its capacity, it should invalidate the least
 * frequently used item before inserting a new item. For the purpose of this
 * problem, when there is a tie (i.e., two or more keys that have the same
 * frequency), the least recently used key would be evicted.
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * LFUCache cache = new LFUCache( 2 /* capacity */ );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.get(3);       // returns 3.
 * cache.put(4, 4);    // evicts key 1.
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 */
class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minCount = 0;
    }
    
    int get(int key) {
        if(!values.count(key)){
            return -1;
        }
        
        int value = values[key];
        put(key, value);
        
        return value;
    }
    
    void put(int key, int value) {
        if(capacity <= 0){
            return;
        }
        
        if(values.count(key)){
            pair<int, list<int>::iterator> p = pos[key];
            
            counts[p.first].erase(p.second);
            if(counts[p.first].empty()){
                counts.erase(p.first);
            }
            
            int c = p.first + 1;
            counts[c].push_back(key);
            
            pos[key] = make_pair(c, --counts[c].end());
            
            if(!counts.count(minCount)){
                minCount = c;
            }
            
            values[key] = value;
            return;
        }
        
        //replace
        if(values.size()>=capacity){
           int eraseKey = counts[minCount].front();
           
           counts[minCount].pop_front();
           values.erase(eraseKey);
           pos.erase(eraseKey);
           
           if(counts[minCount].empty()){
               counts.erase(minCount);
           }
        }
        
        counts[1].push_back(key);
        pos[key] = make_pair(1, --counts[1].end());
        minCount = 1;
        
        values[key] = value;
    }
    
private:
    map<int, int> values;
    map<int, list<int> > counts;
    map<int, pair<int, list<int>::iterator> > pos;
    
    int minCount;
    int capacity;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
