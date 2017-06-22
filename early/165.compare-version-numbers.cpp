/*
 * [165] Compare Version Numbers
 *
 * https://leetcode.com/problems/compare-version-numbers
 *
 * Medium (19.83%)
 * Total Accepted:    83171
 * Total Submissions: 419425
 * Testcase Example:  '"1"\n"0"'
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise
 * return 0.
 * 
 * You may assume that the version strings are non-empty and contain only
 * digits and the . character.
 * The . character does not represent a decimal point and is used to separate
 * number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it
 * is the fifth second-level revision of the second first-level revision.
 * 
 * Here is an example of version numbers ordering:
 * 0.1 < 1.1 < 1.2 < 13.37
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    vector<int> split(string s){
        vector<int> v;
        int start = 0;
        int i;
        while((i=s.find('.', start))!=string::npos){
            if(i>start) { v.push_back(atoi(s.substr(start, i-start).c_str())); }
            start = i + 1;
        }
        if(start < s.size()) { v.push_back(atoi(s.substr(start, s.size() - start).c_str())); }
        return v;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        
        int diff = v1.size() - v2.size();
        for(int i=0;i<diff;i++) { v2.push_back(0); }
        for(int i=0;i<-diff;i++) { v1.push_back(0); }
        
        int i = 0, j = 0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i] != v2[j]) { return v1[i] > v2[j] ? 1 : -1; }
            i++;
            j++;
        }
        
        return 0;
    }
};
