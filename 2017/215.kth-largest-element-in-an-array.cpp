/*
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array
 *
 * Medium (38.75%)
 * Total Accepted:    131138
 * Total Submissions: 338377
 * Testcase Example:  '[1]\n1'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:

    void findKth(vector<int>& nums, int begin, int end, int k, int& res){
        if(begin>end || k<begin || k>end) { return; }
        
        int mid = begin + (end-begin)/2;
        swap(nums[begin], nums[mid]);
        
        int poivt = nums[begin];
        
        int i = begin, j = end;
        while(i<j){
            while(i<j && nums[i]<=poivt) i++;
            while(i<j && nums[j]>poivt) j--;
            
            if(i<j) { swap(nums[i], nums[j]); i++; j--; }
        }
        
        int index = nums[i] <= poivt ? i : i -1;
        swap(nums[index], nums[begin]);
        
        if(k==index) { res = poivt; }
        else if(k < index){
            findKth(nums, begin, index - 1, k, res);
        }
        else{
            findKth(nums, index+1, end, k, res);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty() || k<=0 || k > nums.size()) { return -1; }
        
        int res = -1;
        findKth(nums, 0, nums.size() - 1, nums.size() - k, res);
        
        return res;
    }
};
