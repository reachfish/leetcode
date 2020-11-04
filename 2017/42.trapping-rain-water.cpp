/*
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water
 *
 * Hard (36.33%)
 * Total Accepted:    112351
 * Total Submissions: 309244
 * Testcase Example:  '[]'
 *
 * 
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after
 * raining. 
 * 
 * 
 * 
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 * 
 * 
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 */

class Solution {

public:
    int trap(vector<int>& height) {
        vector<int> left(height.size());
        vector<int> right(height.size());
        
        int leftMax = 0;
        int rightMax = 0;
        for(int i=0, j=height.size()-1;i<height.size();i++,j--){
            leftMax = leftMax > height[i] ? leftMax : height[i];
            rightMax = rightMax > height[j] ? rightMax : height[j];
            left[i] = leftMax;
            right[j] = rightMax;
        }
        
        int all = 0;
        for(int i=0;i<height.size();i++){
            int value = height[i];
            if(left[i]>value && right[i]>value){
                int min = left[i] < right[i] ? left[i] : right[i];
                all += min - value;
            }
        }
        
        return all;
    }
};
