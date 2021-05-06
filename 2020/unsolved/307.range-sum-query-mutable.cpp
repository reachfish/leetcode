/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (36.58%)
 * Likes:    1779
 * Dislikes: 106
 * Total Accepted:    134.9K
 * Total Submissions: 364K
 * Testcase Example:
 * '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an array nums and two types of queries where you should update the
 * value of an index in the array, and retrieve the sum of a range in the
 * array.
 *
 * Implement the NumArray class:
 *
 *
 * NumArray(int[] nums) initializes the object with the integer array nums.
 * void update(int index, int val) updates the value of nums[index] to be
 * val.
 * int sumRange(int left, int right) returns the sum of the subarray nums[left,
 * right] (i.e., nums[left] + nums[left + 1], ..., nums[right]).
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["NumArray", "sumRange", "update", "sumRange"]
 * [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 * Output
 * [null, 9, null, 8]
 *
 * Explanation
 * NumArray numArray = new NumArray([1, 3, 5]);
 * numArray.sumRange(0, 2); // return 9 = sum([1,3,5])
 * numArray.update(1, 2);   // nums = [1,2,5]
 * numArray.sumRange(0, 2); // return 8 = sum([1,2,5])
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -100 <= nums[i] <= 100
 * 0 <= index < nums.length
 * -100 <= val <= 100
 * 0 <= left <= right < nums.length
 * At most 3 * 10^4 calls will be made to update and sumRange.
 *
 *
 */

// @lc code=start
class NumArray {
 public:
  NumArray(vector<int>& nums) {
    nums_ = nums;
    sums_.resize(nums.size() + 1);
    sums_[0] = 0;
    int i = 1;
    for (auto n : nums) {
      sums_[i] = sums_[i - 1] + n;
      i++;
    }
  }

  void update(int index, int val) {
    int diff = val - nums_[index];
    nums_[index] = val;
    for (int i = index + 1; i < sums_.size(); i++) {
      sums_[i] += diff;
    }
  }

  int sumRange(int left, int right) { return sums_[right + 1] - sums_[left]; }

 private:
  vector<int> sums_;
  vector<int> nums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
