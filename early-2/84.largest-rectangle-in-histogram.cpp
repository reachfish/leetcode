/*
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram
 *
 * Hard (26.30%)
 * Total Accepted:    89516
 * Total Submissions: 340398
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * For example,
 * Given heights = [2,1,5,6,2,3],
 * return 10.
 * 
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);

		int max = 0;

		stack<int> index;
		for(int i=0;i<heights.size();i++){
			while(!index.empty() && heights[i] <= heights[index.top()]){
				int j = index.top();
				index.pop();

				int w = i - 1 - (index.empty() ? -1 : index.top());
				int area = heights[j] * w;

				max = max > area ? max : area;
			}

			index.push(i);
		}

		return max;
    }
};
