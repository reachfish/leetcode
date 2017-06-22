/*
 * [386] Lexicographical Numbers
 *
 * https://leetcode.com/problems/lexicographical-numbers
 *
 * Medium (40.66%)
 * Total Accepted:    18448
 * Total Submissions: 45372
 * Testcase Example:  '13'
 *
 * 
 * Given an integer n, return 1 - n in lexicographical order.
 * 
 * 
 * 
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 * 
 * 
 * 
 * Please optimize your algorithm to use less time and space. The input size
 * may be as large as 5,000,000.
 * 
 */
/*
 * [386] Lexicographical Numbers
 *
 * https://leetcode.com/problems/lexicographical-numbers
 *
 * Medium (40.66%)
 * Total Accepted:    18448
 * Total Submissions: 45372
 * Testcase Example:  '13'
 *
 * 
 * Given an integer n, return 1 - n in lexicographical order.
 * 
 * 
 * 
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 * 
 * 
 * 
 * Please optimize your algorithm to use less time and space. The input size
 * may be as large as 5,000,000.
 * 
 */
class Solution {
public:
    void helper(vector<int>& res, int v, int n) {
        if(v > n) { return; }
        res.push_back(v);
        for(int i=0; i<=9; i++){
            helper(res, 10 * v + i, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1; i<= 9; i++) {
            helper(res, i, n);
        }

        return res;
    }
};

