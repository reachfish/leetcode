/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx
 *
 * Easy (27.59%)
 * Total Accepted:    154031
 * Total Submissions: 558254
 * Testcase Example:  '0'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x.
 */
class Solution {
public:
    int mySqrt(int x) {
        if(x<0){
            return -1;
        }
        
        if(x==0){
            return 0;
        }
        
        int i = 1;
        int j = x;
        while(i<j){
            int mid = (i+j)/2;
            int d = mid - x/mid;
            if(d==0){
                return mid;
            }
            else if(d<0){
                i = mid + 1;
            }
            else{
                j = mid -1;
            }
        }
        
        return i <= x/i ? i : i-1;
    }
};
