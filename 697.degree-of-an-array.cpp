/*
 * [697] Degree of an Array
 *
 * https://leetcode.com/problems/degree-of-an-array
 *
 * algorithms
 * Easy (48.06%)
 * Total Accepted:    7.4K
 * Total Submissions: 15.6K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 * 
 * Example 1:
 * 
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation: 
 * The input array has a degree of 2 because both elements 1 and 2 appear
 * twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 * 
 * 
 * 
 * Note:
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 * 
 */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
		map<int, int> pos;        
		map<int, int> freqs;

		int degree = 0;
		int min_len = nums.size();

		for(int i=0; i<nums.size(); i++)
		{
			int num = nums[i];
			freqs[num]++;
			if(!pos.count(num)){
				pos[num] = i;
			}

			int len = i - pos[num] + 1;
			if(freqs[num] > degree)
			{
				min_len = len;
				degree = freqs[num];
			}
			else if(freqs[num] == degree && min_len > len)
			{
				min_len = len;
			}
		}

		return min_len;
    }
};
