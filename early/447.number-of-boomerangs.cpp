/*
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs
 *
 * Easy (44.33%)
 * Total Accepted:    21196
 * Total Submissions: 47819
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is
 * a tuple of points (i, j, k) such that the distance between i and j equals
 * the distance between i and k (the order of the tuple matters).
 * 
 * Find the number of boomerangs. You may assume that n will be at most 500 and
 * coordinates of points are all in the range [-10000, 10000] (inclusive).
 * 
 * Example:
 * 
 * Input:
 * [[0,0],[1,0],[2,0]]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 * 
 * 
 */
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for(int i=0;i<points.size();i++){
            pair<int, int> p1 = points[i];
            map<int, int> dist;
            for(int j=0;j<points.size();j++){
                if(i==j){
                    continue;
                }
                
                pair<int, int> p2 = points[j];
                int d = (p1.first-p2.first) * (p1.first-p2.first) + (p1.second-p2.second) * (p1.second - p2.second);
                dist[d]++;
            }
            
            for(auto it=dist.begin();it!=dist.end();it++){
                int count = it->second;
                res += count * (count -1);
            }
        }
        
        return res;
    }
};
