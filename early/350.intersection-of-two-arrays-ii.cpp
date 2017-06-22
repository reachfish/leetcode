/*
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii
 *
 * Easy (44.35%)
 * Total Accepted:    65496
 * Total Submissions: 147677
 * Testcase Example:  '[]\n[]'
 *
 * 
 * Given two arrays, write a function to compute their intersection.
 * 
 * 
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 * 
 * 
 * Note:
 * 
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 * 
 * 
 * 
 * Follow up:
 * 
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 * 
 * 
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m1;
        map<int, int> m2;
        for(int i=0;i<nums1.size();i++){
            m1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            m2[nums2[i]]++;
        }
        
        vector<int> res;
        for(auto it=m1.begin();it!=m1.end();it++){
            int min = it->second < m2[it->first] ? it->second : m2[it->first];
            for(int i=0;i<min;i++){
                res.push_back(it->first);
            }
        }
        
        return res;
    }
};
