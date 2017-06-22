/*
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title
 *
 * Easy (25.55%)
 * Total Accepted:    101028
 * Total Submissions: 395490
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 * 
 * For example:
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n){
            s = string(1, 'A' + (n-1)%26) + s;
            n = (n-1)/26;
        }
        
        return s;
    }
};
