/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (47.24%)
 * Likes:    1254
 * Dislikes: 1337
 * Total Accepted:    251.5K
 * Total Submissions: 520.1K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n' +
  '[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices
 * left and right inclusive, where (left <= right).
 *
 * Implement the NumArray class:
 *
 *
 * NumArray(int[] nums) initializes the object with the integer array nums.
 * int sumRange(int left, int right) returns the sum of the elements of the
 * nums array in the range [left, right] inclusive (i.e., sum(nums[left],
 * nums[left + 1], ... , nums[right])).
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["NumArray", "sumRange", "sumRange", "sumRange"]
 * [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
 * Output
 * [null, 1, -1, -3]
 *
 * Explanation
 * NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
 * numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
 * numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1))
 * numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^5 <= nums[i] <= 10^5
 * 0 <= left <= right < nums.length
 * At most 10^4 calls will be made to sumRange.
 *
 *
 */

// @lc code=start
class NumArray {
 public:
  NumArray(vector<int>& nums) {
    sum_.resize(nums.size());
    int s = 0;
    int i = 0;
    for (auto n : nums) {
      s += n;
      sum_[i++] = s;
    }
  }

  int sumRange(int left, int right) {
    if (left <= 0) {
      return sum_[right];
    } else {
      return sum_[right] - sum_[left - 1];
    }
  }

  vector<int> sum_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
