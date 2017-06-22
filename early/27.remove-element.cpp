/*
 * [27] Remove Element
 *
 * https://leetcode.com/problems/remove-element
 *
 * Easy (38.45%)
 * Total Accepted:    196827
 * Total Submissions: 511878
 * Testcase Example:  '[3,2,2,3]\n3'
 *
 * Given an array and a value, remove all instances of that value in place and
 * return the new length.
 * 
 * 
 * Do not allocate extra space for another array, you must do this in place
 * with constant memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 * 
 * 
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 * 
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 2.
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()){
            return 0;
        }
        
        vector<int>::iterator it1 = nums.begin();
        vector<int>::iterator it2 = nums.begin() + nums.size() - 1;
        do{
            while(it1 < it2 && *it1 != val)
                it1++;
            while(it1 < it2 && *it2 == val)
                it2--;
            
            if(it1 >= it2){
                break;
            }
            
            int tmp = *it1;
            *it1 = *it2;
            *it2 = tmp;
            it1++;
            it2--;
        }while(1);
        
        if(*it1 != val){
            it1++;
        }
        
        nums.erase(it1, nums.end());
        
        return nums.size();
    }
};
