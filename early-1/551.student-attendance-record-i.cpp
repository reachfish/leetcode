/*
 * [551] Student Attendance Record I
 *
 * https://leetcode.com/problems/student-attendance-record-i
 *
 * Easy (43.51%)
 * Total Accepted:    10907
 * Total Submissions: 25074
 * Testcase Example:  '"PPALLP"'
 *
 * You are given a string representing an attendance record for a student. The
 * record only contains the following three characters:
 * 
 * 
 * 
 * 'A' : Absent. 
 * 'L' : Late.
 * ⁠'P' : Present. 
 * 
 * 
 * 
 * 
 * A student could be rewarded if his attendance record doesn't contain more
 * than one 'A' (absent) or more than two continuous 'L' (late).    
 * 
 * You need to return whether the student could be rewarded according to his
 * attendance record.
 * 
 * Example 1:
 * 
 * Input: "PPALLP"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "PPALLL"
 * Output: False
 * 
 * 
 */
class Solution {
public:
    bool checkRecord(string s) {
        bool haveA = false;
        for(int i=0;i<s.size();i++){
            char c = s.at(i);
            if(c=='A'){
                if(haveA){
                    return false;
                }
                haveA = true;
            }
            else if(c=='L' && i>=2){
                if(s.at(i-1)=='L' && s.at(i-2)=='L'){
                    return false;
                }
            }
        }
        
        return true;
    }
};
