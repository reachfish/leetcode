/*
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements
 *
 * algorithms
 * Medium (35.52%)
 * Total Accepted:    4.8K
 * Total Submissions: 13.5K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * 
 * Given a sorted array, two integers k and x, find the k closest elements to x
 * in the array.  The result should also be sorted in ascending order.
 * If there is a tie,  the smaller elements are always preferred.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,3,4,5], k=4, x=3
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4,5], k=4, x=-1
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * Note:
 * 
 * The value k is positive and will always be smaller than the length of the
 * sorted array.
 * ⁠Length of the given array is positive and will not exceed 104
 * ⁠Absolute value of elements in the array and x will not exceed 104
 * 
 * 
 */
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		if(arr.empty() || k<=0){
			return vector<int>();
		}

		deque<int> que;        

		int len = arr.size();
		int j = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
		int i = j - 1;

		while(k--){
			if(i<0 || (j<len && (arr[j] - x < x - arr[i]))){
				que.push_back(arr[j++]);
			}
			else{
				que.push_front(arr[i--]);
			}
		}

		vector<int> res;
		for(auto v : que){
			res.push_back(v);
		}

		return res;
    }
};
