/*
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string
 *
 * Easy (36.89%)
 * Total Accepted:    21293
 * Total Submissions: 57719
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 * 
 * Please note that the string does not contain any non-printable characters.
 * 
 * Example:
 * 
 * Input: "Hello, my name is John"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    int countSegments(string s) {
        int start = 0;
        int pos;
        int count = 0;
        while((pos=s.find(' ', start))!=string::npos){
            if(pos > start){ count++; }
            start = pos + 1;
        }
        if(start < s.size()) count++;
        
        return count;
    }
};
