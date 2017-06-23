/*
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence
 *
 * Medium (38.86%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 * 
 * 
 * Formally the function should:
 * Return true if there exists i, j, k  
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 
 * else return false.
 * 
 * 
 * 
 * Your algorithm should run in O(n) time complexity and O(1) space
 * complexity.
 * 
 * 
 * Examples:
 * Given [1, 2, 3, 4, 5],
 * return true.
 * 
 * 
 * Given [5, 4, 3, 2, 1],
 * return false.
 * 
 * 
 * Credits:Special thanks to @DjangoUnchained for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        for(auto n : nums){
            if(n <= c1) { c1 = n; }
            else if(n <= c2) { c2 = n; }
            else { return true; }
        }

        return false;
    }

    bool increasingTriplet2(vector<int>& nums) {
        vector<int> v;        
        for(auto n : nums){
            int len = v.size();
            if(len == 0) { 
                v.push_back(n); 
                continue; 
            }

            if(n == v.back()) { continue; }

            if(len == 1){
                if(n < v.back()) { v.pop_back(); }
                v.push_back(n);  // 1 < 2
            }
            else if(len == 2){
                if(n > v.back()) { return true; }
                if(n == v[0]) { continue; }

                if(n > v[0]) { v.pop_back(); }
                v.push_back(n);  // 1 < 2 > 3  或者 1 < 3
            }
            else{  //三个元素： 此时  1< 2 > 3 && 1 > 3
                if(n > v[1]) { return true; }
                if(n > v.back()) {
                    v.erase(v.begin(), v.begin() + 2);
                }
                else{
                    v.pop_back();
                }

                v.push_back(n);
            }
        }

        return false;
    }
};
