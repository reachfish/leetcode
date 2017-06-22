/*
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii
 *
 * Hard (26.14%)
 * Total Accepted:    91747
 * Total Submissions: 350987
 * Testcase Example:  '[0]'
 *
 * 
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * 
 * Each element in the array represents your maximum jump length at that
 * position. 
 * 
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * 
 * 
 * For example:
 * Given array A = [2,3,1,1,4]
 * 
 * 
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from
 * index 0 to 1, then 3 steps to the last index.)
 * 
 * 
 * 
 * Note:
 * You can assume that you can always reach the last index.
 */
class Solution {
public:
    int max(int v1, int v2){
        return v1 >= v2 ? v1 : v2;
    }
    
    int jump(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        
        int count = 0;
        int end1 = 0;
        int end2 = 0 + nums[0];
        for(int i=1;i<nums.size();i++){
            if(i<=end1){//count[i] = count[i-1]
                end2 = max(end2, i+nums[i]);
            }
            else{//count[i] = count[i-1] + 1
                if(i<=end2){
                    count++;
                    end1 = end2;
                    end2 = i + nums[i];
                }
                else{
                    return -1;
                }
            }
        }
        
        return count;
    }
};
