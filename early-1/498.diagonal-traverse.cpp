/*
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse
 *
 * Medium (46.02%)
 * Total Accepted:    7774
 * Total Submissions: 16897
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image. 
 * 
 * 
 * Example:
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output:  [1,2,4,7,5,3,6,8,9]
 * Explanation:
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The total number of elements of the given matrix will not exceed 10,000.
 * 
 * 
 */
class Solution {
public:
    int min(int a, int b){
        return a < b ? a : b;    
    }
    
    int max(int a, int b){
        return a > b ? a : b;
    }
    
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m==0){
            return res;
        }
        int n = matrix[0].size();
        if(n==0){
            return res;
        }
        
        bool flag = true;
        for(int k=0;k<=m+n-2;k++){
            if(flag){
               int j = max(0, k - (m-1));
               int i = k - j;
               while(i>=0 && j < n){
                   res.push_back(matrix[i--][j++]);
               }
            }
            else{
                int i = max(0, k-(n-1));
                int j = k - i;
                while(i<m && j>=0){
                    res.push_back(matrix[i++][j--]);
                }
            }
            
            flag = !flag;
        }
        
        return res;
    }
};
