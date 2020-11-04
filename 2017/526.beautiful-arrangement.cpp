/*
 * [526] Beautiful Arrangement
 *
 * https://leetcode.com/problems/beautiful-arrangement
 *
 * Medium (54.99%)
 * Total Accepted:    9503
 * Total Submissions: 17282
 * Testcase Example:  '2'
 *
 * 
 * Suppose you have N integers from 1 to N. We define a beautiful arrangement
 * as an array that is constructed by these N numbers successfully if one of
 * the following is true for the ith position (1 ≤ i ≤ N) in this array:
 * 
 * The number at the ith position is divisible by i.
 * i is divisible by the number at the ith position.
 * 
 * 
 * 
 * 
 * Now given N, how many beautiful arrangements can you construct?
 * 
 * 
 * Example 1:
 * 
 * Input: 2
 * Output: 2
 * Explanation: 
 * The first beautiful arrangement is [1, 2]:
 * Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
 * Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
 * The second beautiful arrangement is [2, 1]:
 * Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
 * Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and will not exceed 15.
 * 
 * 
 */
class Solution {
public:
    int match(int a, int b) {
        return a % b == 0 || b % a == 0;    
    }
    
    int countArr(vector<int>& v, int index) {
        if(index==v.size()) { return 1; }
        
        int count = 0;
        for(int i=index;i<v.size();i++){
            if(match(index, v[i])){
                int a = v[index];
                int b = v[i];
                
                v[index] = b;
                v[i] = a;
                count += countArr(v, index + 1);
                v[index] = a;
                v[i] = b;
            }
        }
        
        return count;
    }
    
    int countArrangement(int N) {
        if(N<0) { return 0; }
        
        vector<int> a(N+1);
        for(int i=0;i<=N;i++) a[i] = i;
        
        return countArr(a, 1);    
    }
};
