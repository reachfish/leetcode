/*
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence
 *
 * Hard (36.45%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * 
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its
 * length: 4.
 * 
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		int max = 0;
		map<int, int> m;
		for(auto num : nums){
			if(m.count(num)) {
				continue;
			}

			int left = m.count(num-1) ? m[num-1] : 0;
			int right = m.count(num+1) ? m[num+1] : 0;
			int sum = left + right + 1;

			max = max > sum ? max : sum;

			m[num] = m[num-left] = m[num+right] = sum;
		}

		return max;
    }
};
