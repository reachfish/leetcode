/*
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals
 *
 * Medium (29.51%)
 * Total Accepted:    124820
 * Total Submissions: 422904
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * 
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    
    static bool compare(const Interval& a, const Interval& b){
        return a.start < b.start;    
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.empty()) { return res; }
        
        sort(intervals.begin(), intervals.end(), Solution::compare);
        res.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++){
            if(res.back().end >= intervals[i].start){
                res.back().end = max(res.back().end, intervals[i].end);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};
