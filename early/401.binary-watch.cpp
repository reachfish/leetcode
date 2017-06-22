/*
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch
 *
 * Easy (44.84%)
 * Total Accepted:    29627
 * Total Submissions: 66080
 * Testcase Example:  '0'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the
 * right.
 * 
 * For example, the above binary watch reads "3:25".
 * 
 * Given a non-negative integer n which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent.
 * 
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
 * "0:08", "0:16", "0:32"]
 * 
 * 
 * Note:
 * 
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid,
 * it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for
 * example "10:2" is not valid, it should be "10:02".
 * 
 * 
 */
class Solution {
public:

    int bitCount(int num){
        int count = 0;
        while(num){
            count++;
            num &= num-1;
        }
        
        return count;
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        if(num<0||num>10){
            return res;
        }
        
        vector<vector<string> > hour(5);
        vector<vector<string> > min(7);
        
        for(int i=0;i<12;i++){
            hour[bitCount(i)].push_back(to_string(i));
        }
        
        for(int i=0;i<60;i++){
            min[bitCount(i)].push_back((i<10?"0":"") + to_string(i));
        }
        
        for(int h=0;h<=num;h++){
            int m = num - h;
            if(h>=hour.size()||m>=min.size()){
                continue;
            }
            
            for(int i=0;i<hour[h].size();i++){
                for(int j=0;j<min[m].size();j++){
                    res.push_back(hour[h][i]+":"+min[m][j]);
                }
            }
        }
        
        return res;
    }
};
