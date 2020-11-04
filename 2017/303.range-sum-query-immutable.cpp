/*
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable
 *
 * Easy (28.63%)
 * Total Accepted:    67882
 * Total Submissions: 237088
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */
class NumArray {
public:
    NumArray(vector<int> nums) {
        int s = 0;
        for(int i=0;i<nums.size();i++){
            s += nums[i];
            sum.push_back(s);
        }
    }
    
    int sumRange(int i, int j) {
        if(i<0||j>=sum.size()||i>j){
            return 0;
        }
        
        return sum[j] - (i ? sum[i-1] : 0);
    }
    
private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
