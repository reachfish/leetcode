/*
 * [493] Reverse Pairs
 *
 * https://leetcode.com/problems/reverse-pairs
 *
 * Hard (19.46%)
 * Total Accepted:    4812
 * Total Submissions: 24731
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * Given an array nums, we call (i, j) an important reverse pair if i < j and
 * nums[i] > 2*nums[j].
 * 
 * You need to return the number of important reverse pairs in the given
 * array.
 * 
 * Example1:
 * 
 * Input: [1,3,2,3,1]
 * Output: 2
 * 
 * 
 * Example2:
 * 
 * Input: [2,4,3,5,1]
 * Output: 3
 * 
 * 
 * Note:
 * 
 * The length of the given array will not exceed 50,000.
 * All the numbers in the input array are in the range of 32-bit integer.
 * 
 * 
 */
class Solution {
public:
    int mergeSort(vector<int> &nums, int begin, int end){
        if(begin >= end){
            return 0;
        }
        
        int mid = (begin+end)/2;
        int ret = mergeSort(nums, begin, mid) + mergeSort(nums,mid+1, end);
        
        vector<int> left;
        vector<int> right;
        for(int i=begin;i<=mid;i++){
            left.push_back(nums[i]);
        }
        for(int j=mid+1;j<=end;j++){
            right.push_back(nums[j]);
        }
        
        int i = 0, j = 0, size1 = left.size(), size2 = right.size();
        int k = begin;
        int m = 0;
        while(i<size1 || j < size2){
            if(i < size1 && (j>= size2 || left[i]<=right[j])){
                
                while(m<size2 && left[i] > 2L * right[m]){
                    m++;    
                }
                
                ret += m;
                nums[k++] = left[i++];
            }
            else{
                nums[k++] = right[j++];
            }
        }
        
        return ret;
    }
    
    int reversePairs(vector<int>& nums) {
        int val = mergeSort(nums, 0, nums.size()-1);

        return val;
    }
};
