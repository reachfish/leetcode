/*
 * [475] Heaters
 *
 * https://leetcode.com/problems/heaters
 *
 * Easy (29.47%)
 * Total Accepted:    15553
 * Total Submissions: 52779
 * Testcase Example:  '[1,2,3]\n[2]'
 *
 * Winter is coming! Your first job during the contest is to design a standard
 * heater with fixed warm radius to warm all the houses.
 * 
 * Now, you are given positions of houses and heaters on a horizontal line,
 * find out minimum radius of heaters so that all houses could be covered by
 * those heaters.
 * 
 * So, your input will be the positions of houses and heaters seperately, and
 * your expected output will be the minimum radius standard of heaters.
 * 
 * Note:
 * 
 * Numbers of houses and heaters you are given are non-negative and will not
 * exceed 25000.
 * Positions of houses and heaters you are given are non-negative and will not
 * exceed 10^9.
 * As long as a house is in the heaters' warm radius range, it can be warmed.
 * All the heaters follow your radius standard and the warm radius will the
 * same.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,3],[2]
 * Output: 1
 * Explanation: The only heater was placed in the position 2, and if we use the
 * radius 1 standard, then all the houses can be warmed.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4],[1,4]
 * Output: 1
 * Explanation: The two heater was placed in the position 1 and 4. We need to
 * use radius 1 standard, then all the houses can be warmed.
 * 
 * 
 */
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if(houses.empty()) { return 0; }
        if(heaters.empty()) { return INT_MAX; }
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int pos = 0;
        int n = heaters.size();
        
        int max = 0;
        for(auto h : houses){
            while(pos+1 < n && heaters[pos+1] <= h){
                pos++;
            }
            
            int d = abs(h - heaters[pos]);
            if(pos+1 < n){
                int d2 = abs(h-heaters[pos+1]);
                d = d < d2 ? d : d2;
            }
            
            max = max > d ? max : d;
        }
        
        return max;
    }
};
