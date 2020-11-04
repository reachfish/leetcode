/*
 * [406] Queue Reconstruction by Height
 *
 * https://leetcode.com/problems/queue-reconstruction-by-height
 *
 * Medium (55.05%)
 * Total Accepted:    23373
 * Total Submissions: 42456
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * Suppose you have a random list of people standing in a queue. Each person is
 * described by a pair of integers (h, k), where h is the height of the person
 * and k is the number of people in front of this person who have a height
 * greater than or equal to h. Write an algorithm to reconstruct the queue.
 * 
 * 
 * Note:
 * The number of people is less than 1,100.
 * 
 * 
 * Example
 * 
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * 
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 * 
 * 
 */
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<list<pair<int, int>>> m(people.size());
        for(auto p : people) { m[p.second].push_back(p); }
        vector<pair<int,int>> res;
        while(!m.empty() && !m[0].empty()){
            int min = INT_MAX;
            int minK = m.size();
            list<pair<int, int>>::iterator pos;
            for(list<pair<int,int>>::iterator it=m[0].begin();it!=m[0].end();it++){
                if(it->first < min || (it->first==min && it->second < minK)) { min = it->first; minK = it->second; pos = it; }
            }
            res.push_back(*pos);
            m[0].erase(pos);
            
            for(int i=1;i<m.size();i++){
                list<pair<int,int>>::iterator it = m[i].begin();
                while(it!=m[i].end()){
                    if(it->first > min) { it++; }
                    else { m[i-1].push_back(*it); it = m[i].erase(it); }
                }
            }
        }
        
        return res;
    }
};
