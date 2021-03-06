/*
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array
 *
 * Easy (31.86%)
 * Total Accepted:    163736
 * Total Submissions: 513902
 * Testcase Example:  '[1]\n1\n[]\n0'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * 
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2. The number of elements
 * initialized in nums1 and nums2 are m and n respectively.
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = -1;
        if(m > 0){
            k += m;
        }
        if(n > 0){
            k += n;
        }
        
        while(i>=0&&j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }
        
        while(j>=0){
            nums1[k--] = nums2[j--];
        }
    }
};
