/*
 * [593] Valid Square
 *
 * https://leetcode.com/problems/valid-square
 *
 * Medium (38.25%)
 * Total Accepted:    3450
 * Total Submissions: 9019
 * Testcase Example:  '[0,0]\n[1,1]\n[1,0]\n[0,1]'
 *
 * Given the coordinates of four points in 2D space, return whether the four
 * points could construct a square.
 * 
 * The coordinate (x,y) of a point is represented by an integer array with two
 * integers.
 * 
 * Example:
 * 
 * Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
 * Output: True
 * 
 * 
 * 
 * ⁠Note: 
 * 
 * All the input integers are in the range [-10000, 10000].
 * A valid square has four equal sides with positive length and four equal
 * angles (90-degree angles).
 * Input points have no order.
 * 
 * 
 */
class Solution {
public:
    bool checkDist(const vector<int>& p1, const vector<int>& p2, map<int, int>& m){
        int  d = (p2[0]-p1[0]) * (p2[0]-p1[0]) + (p2[1]-p1[1]) * (p2[1] - p1[1]);
        m[d]++;
        return d != 0;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int, int> m;
        
        if(!checkDist(p1, p2, m)) return false;
        if(!checkDist(p1, p3, m)) return false;
        if(!checkDist(p1, p4, m)) return false;
        if(!checkDist(p2, p3, m)) return false;
        if(!checkDist(p2, p4, m)) return false;
        if(!checkDist(p3, p4, m)) return false;
        
        vector<int> dists;
        for(auto d : m){
            dists.push_back(d.first);
        }
        
        if(dists.size()!=2) { return false; }
        int side = dists[0] < dists[1] ? dists[0] : dists[1];
        int orth = dists[0] > dists[1] ? dists[0] : dists[1];
        
        return side * 2 == orth;
    }
};
