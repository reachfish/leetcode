/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule
 *
 * Medium (31.59%)
 * Total Accepted:    80680
 * Total Submissions: 255435
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * 
 * For example:
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0. So it is possible.
 * 
 * 2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0, and to take course 0 you should also have finished course
 * 1. So it is impossible.
 * 
 * Note:
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 * 
 * click to show more hints.
 * 
 * Hints:
 * 
 * This problem is equivalent to finding if a cycle exists in a directed graph.
 * If a cycle exists, no topological ordering exists and therefore it will be
 * impossible to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera
 * explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 * 
 * 
 */
class Solution {
public:
    bool deepVisit(int i, int *final, int *visit, vector<vector<int>>& next){
        if(visit[i]==2) { return true; }
        if(visit[i]==1) { return false; }
        
        visit[i] = 1;
        final[i] = 1;
        for(auto j : next[i]){
            if(!deepVisit(j, final, visit, next)){
                return false;
            }
        }
        
        visit[i] = 2;
        
        return true;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses <= 0 || prerequisites.empty()) { return true; }
        
        vector<vector<int>>  next(numCourses);
        vector<int> root(numCourses, 1);
        int  visit[numCourses];
        int  final[numCourses];
        memset(final, 0, numCourses*sizeof(int));
        
        for(auto pre : prerequisites){
            int child = pre.first;
            int parent = pre.second;
            
            root[child] = 0;
            next[parent].push_back(child);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!root[i]) { continue; }
            memset(visit, 0, numCourses*sizeof(int));
            if(!deepVisit(i, final, visit, next)) { return false; }
        }
        
        for(int i=0;i<numCourses;i++){
            if(!final[i]) { return false; }    
        }
        
        return true;
    }
};
