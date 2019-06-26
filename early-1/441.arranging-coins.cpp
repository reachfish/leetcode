/*
 * [441] Arranging Coins
 *
 * https://leetcode.com/problems/arranging-coins
 *
 * Easy (36.25%)
 * Total Accepted:    26348
 * Total Submissions: 72693
 * Testcase Example:  '5'
 *
 * You have a total of n coins that you want to form in a staircase shape,
 * where every k-th row must have exactly k coins.
 * ⁠
 * Given n, find the total number of full staircase rows that can be formed.
 * 
 * n is a non-negative integer and fits within the range of a 32-bit signed
 * integer.
 * 
 * Example 1:
 * 
 * n = 5
 * 
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤
 * 
 * Because the 3rd row is incomplete, we return 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * n = 8
 * 
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤ ¤
 * ¤ ¤
 * 
 * Because the 4th row is incomplete, we return 3.
 * 
 * 
 */
class Solution {
public:
    int arrangeCoins(int n) {
        if(n<0){
            return -1;
        }
        
        if(n==0){
            return 0;
        }
        
        int i = 1;
        int j = n;
        while(i<j){
            int mid = i + (j-i)/2;
            int d = mid - 2L*n/(mid+1);
            if(d==0){
                return mid;
            }
            else if(d<0){
                i = mid + 1;
            }
            else{
                j = mid - 1;
            }
        }
        
        return i - 2L*n/(i+1) <=0 ? i : i-1;
    }
};
