/*
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler
 *
 * Medium (33.24%)
 * Total Accepted:    621
 * Total Submissions: 1857
 * Testcase Example:  '[\'A\',\'A\',\'A\',\'B\',\'B\',\'B\']\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks.Tasks could
 * be done without original order. Each task could be done in one interval. For
 * each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle. 
 * 
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 * 
 * Example 1:
 * 
 * Input: tasks = ['A','A','A','B','B','B'], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * 
 * 
 * 
 * Note:
 * 
 * The number of tasks is in the range [1, 10000].
 * 
 * 
 */
class Solution {
public:
    static bool compare(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second; 
    }

    int leastInterval(vector<char>& tasks, int n) {
        int cnt[32];
        int time[32];
        for(int i = 0; i< 32; i++) { cnt[i] = time[i] = 0; }
        for(auto c : tasks) { cnt[c-'A']++; }
        vector<pair<int, int>> v;
        for(int i=0;i<32;i++) { 
            if(cnt[i]) { v.push_back(make_pair(i, cnt[i]));  }
        }

        sort(v.begin(), v.end(), Solution::compare);

        int t = 0;
        while(!v.empty()){
            int minT = INT_MAX;
            int pos = -1;
            t++;
            for(int i=0;i<v.size();i++){
                int c = v[i].first;
                if(time[c] <= t) {
                    pos = i;
                    break;
                }
                else if(time[c] < minT){
                    minT = time[c];
                    pos = i;
                }
            }

            int c = v[pos].first;
            if(t < time[c]) { t = time[c]; }
            time[c] = t + n + 1;

            //printf("(%d:%c, next:%d),", t, c+'A', time[c]);

            v[pos].second--;
            if(v[pos].second==0) { v.erase(v.begin() + pos); }
            else{
                //后移
                for(int i=pos;i<v.size()-1&&v[i].second<v[i+1].second;i++){
                    swap(v[i], v[i+1]);
                }
            }
        }

        return t;
    }
};
