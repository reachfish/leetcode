/*
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements
 *
 * Medium (47.55%)
 * Total Accepted:    62370
 * Total Submissions: 131184
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 * 
 * 
 * Note: 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 */
class Solution {
public:
    static bool compare(const pair<int,int>& a, const pair<int, int>& b){
        return a.second > b.second;    
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty()||k<=0) { return vector<int>(); }
        
        map<int, int> m;
        for(auto num : nums){
            m[num]++;    
        }
        
        vector<pair<int, int>> v;
        map<int, int>::iterator it;
        int count;
        for(it=m.begin(), count = 0; it!=m.end()&&count < k;count++, it++){
            v.push_back(make_pair(it->first, it->second));
        }
        
        make_heap(v.begin(), v.end(), Solution::compare);
        
        if(it!=m.end()){
            v.push_back(make_pair(0,0));
            while(it!=m.end()){
                v.back() = *it;
                push_heap(v.begin(), v.end(), Solution::compare);
                pop_heap(v.begin(), v.end(), Solution::compare);
                it++;
            }
            v.pop_back();
        }
        
        sort_heap(v.begin(), v.end(), Solution::compare);
        vector<int> res;
        for(auto e : v){
            res.push_back(e.first);
        }
        
        return res;
    }
};
