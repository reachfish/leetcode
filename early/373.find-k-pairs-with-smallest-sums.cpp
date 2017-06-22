/*
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums
 *
 * Medium (30.50%)
 * Total Accepted:    26825
 * Total Submissions: 87964
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * 
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k. 
 * 
 * 
 * Define a pair (u,v) which consists of one element from the first array and
 * one element from the second array.
 * 
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 * 
 * 
 * Example 1:
 * 
 * Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
 * 
 * Return: [1,2],[1,4],[1,6]
 * 
 * The first 3 pairs are returned from the sequence:
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * 
 * 
 * Example 2:
 * 
 * Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
 * 
 * Return: [1,1],[1,1]
 * 
 * The first 2 pairs are returned from the sequence:
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * 
 * 
 * 
 * Example 3:
 * 
 * Given nums1 = [1,2], nums2 = [3],  k = 3 
 * 
 * Return: [1,3],[2,3]
 * 
 * All possible pairs are returned from the sequence:
 * [1,3],[2,3]
 * 
 * 
 * 
 * Credits:Special thanks to @elmirap and @StefanPochmann for adding this
 * problem and creating all test cases.
 */
#define IV vector<int>::iterator 

class Solution {

public:
    static bool compare(const pair<IV,IV>&a, const pair<IV, IV>& b){
        return *(a.first) + *(a.second) > *(b.first) + *(b.second);    
    }
    
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        if(nums1.empty()||nums2.empty()||k<=0) { return res; }
        
        set<pair<IV, IV>> st;
        vector<pair<IV, IV>> hp;
        hp.push_back(make_pair(nums1.begin(), nums2.begin()));
        while(!hp.empty() && res.size() < k){
            pop_heap(hp.begin(), hp.end(), Solution::compare);
            pair<IV, IV> back = hp.back();
            IV i = back.first;
            IV j = back.second;
            hp.pop_back();
            res.push_back(make_pair(*i, *j));
            if(i+1 != nums1.end() && !st.count(make_pair(i+1, j))) { 
                hp.push_back(make_pair(i+1, j)); 
                push_heap(hp.begin(), hp.end(), Solution::compare); 
                st.insert(make_pair(i+1, j));
            }
            if(j+1 != nums2.end() && !st.count(make_pair(i, j+1))) {
                hp.push_back(make_pair(i, j+1)); 
                push_heap(hp.begin(), hp.end(), Solution::compare); 
                st.insert(make_pair(i, j+1));
            }
        }
        
        return res;
    }
};
