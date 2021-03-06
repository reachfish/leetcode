/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water
 *
 * Medium (36.38%)
 * Total Accepted:    133062
 * Total Submissions: 365806
 * Testcase Example:  '[1,1]'
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;        
        int i = 0; 
        int j = height.size() - 1;
        while(i<j){
            int h = height[i] < height[j] ? height[i] : height[j];
            int val = h * (j - i);
            max = max > val ? max : val;
            while(i<j && height[i] <= h) { i++; }
            while(i<j && height[j] <= h) { j--; }
        }

        return max;
    }
};
