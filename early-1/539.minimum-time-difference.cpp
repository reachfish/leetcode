/*
 * [539] Minimum Time Difference
 *
 * https://leetcode.com/problems/minimum-time-difference
 *
 * Medium (45.60%)
 * Total Accepted:    7374
 * Total Submissions: 16171
 * Testcase Example:  '["23:59","00:00"]'
 *
 * Given a list of 24-hour clock time points in "Hour:Minutes" format, find the
 * minimum minutes difference between any two time points in the list. 
 * 
 * Example 1:
 * 
 * Input: ["23:59","00:00"]
 * Output: 1
 * 
 * 
 * 
 * Note:
 * 
 * The number of time points in the given list is at least 2 and won't exceed
 * 20000.
 * The input time is legal and ranges from 00:00 to 23:59.
 * 
 * 
 */
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int len = 24*60;
        vector<int> count(len, 0);
        
        int maxTime = -1;
        for(int i =0;i<timePoints.size();i++){
            string time = timePoints[i];
            int hour = atoi(time.substr(0,2).c_str());
            int min = atoi(time.substr(3,2).c_str());
            int t = hour*60+min;
            
            if(count[t]){
                return 0;
            }
            
            count[t]++;
            
            maxTime = maxTime > t ? maxTime : t;
        }
        
        int res = INT_MAX;
        int cur = maxTime;
        for(int i=0;i<len;i++){
            if(!count[i]){
                continue;
            }
            
            int diff = (i - cur + len)%len;

            res = res < diff ? res : diff;
            cur = i;
        }
        
        return res;
    }
};
