/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (48.20%)
 * Likes:    4238
 * Dislikes: 245
 * Total Accepted:    575.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order red, white, and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Follow up:
 * 
 * 
 * Could you solve this problem without using the library's sort function?
 * Could you come up with a one-pass algorithm using only O(1) constant
 * space?
 * 
 * 
 * 
 * Example 1:
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * Example 2:
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 * Example 3:
 * Input: nums = [0]
 * Output: [0]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] is 0, 1, or 2.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }

        int start[]    = {-1, -1, -1};
        start[nums[0]] = 0;

        for (int i = 1; i < nums.size(); i++) {
            int prev = nums[i - 1];
            int cur  = nums[i];
            if (prev == cur) {
                continue;
            }

            if (prev < cur) {
                start[cur] = i;
                continue;
            }

            for (int k = cur + 1; k <= 2; k++) {
                int pos = start[k];
                if (pos >= 0) {
                    nums[i]   = k;
                    nums[pos] = cur;

                    if (start[cur] == -1) {
                        start[cur] = pos;
                    }

                    start[k] = -1;
                    for (int j = pos + 1; j < i; j++) {
                        if (nums[j] == k) {
                            start[k] = j;
                            break;
                        }
                        if (nums[j] > k) {
                            break;
                        }
                    }

                    i--;
                    break;
                }
            }
        }
    }
};
// @lc code=end
