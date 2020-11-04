/*
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path
 *
 * Medium (24.89%)
 * Total Accepted:    85218
 * Total Submissions: 342344
 * Testcase Example:  '"/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 * 
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * 
 * 
 * click to show corner cases.
 * 
 * Corner Cases:
 * 
 * 
 * 
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together,
 * such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 * 
 * 
 */
class Solution {
public:
    void dealSub(vector<string>& stk, string s){
        if(s.empty() || s=="."){
            return;
        }
        
        if(s==".."){
            if(!stk.empty()){
                stk.pop_back();
            }
        }
        else{
            stk.push_back(s);
        }
    }
    
    string simplifyPath(string path) {
        size_t begin=0, end = 0;
        vector<string> stk;
        while((end=path.find('/', begin))!=string::npos){
            string s = path.substr(begin, end-begin);
            dealSub(stk, s);
            
            begin = end + 1;
        }
        
        if(begin<path.size()){
            dealSub(stk, path.substr(begin, path.size()-begin));
        }
        
        string res;
        for(int i=0;i<stk.size();i++){
            res += "/" + stk[i];
        }
        
        if(res.empty()){
            res = "/";
        }
        
        return res;
    }
};
