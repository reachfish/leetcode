/*
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division
 *
 * Medium (40.56%)
 * Total Accepted:    15139
 * Total Submissions: 37321
 * Testcase Example:  '[ ["a","b"],["b","c"] ]\n[2.0,3.0]\n[ ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]'
 *
 * 
 * Equations are given in the format A / B = k, where  A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 * 
 * Example:
 * Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e
 * = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 * 
 * 
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 * 
 * 
 * According to the example above:
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ]. 
 * 
 * 
 * 
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 * 
 */
class Solution {
public:
    //a = b * val;
    void helper(string a, string b, double val, map<string, map<string,double>>& g, map<string, pair<string, double>>& v){
        if(v.count(a)) { return ; }
        v[a] = make_pair(b, val);

        for(auto eq : g[a]){
            //a = c * eq.second, so c = b * (val / eq.second)
            string c = eq.first;
            helper(c, b, val/eq.second, g, v);
        }
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string, map<string, double>> g;        
        for(int i = 0; i<equations.size(); i++){
            pair<string, string> eq = equations[i];
            string a = eq.first, b = eq.second;
            g[a][b] = values[i]; 
            g[b][a] = 1/values[i];
        }

        map<string, pair<string, double>> v;
        for(auto it : g){
            helper(it.first, it.first, 1, g, v);
        }

        //for(auto it : v) { printf("%s=%f*%s,", it.first.c_str(), it.second.second, it.second.first.c_str()); }

        vector<double> res; 
        for(auto  q : queries){
            string a = q.first; 
            string b = q.second; 

            res.push_back(v.count(a) && v.count(b) && v[a].first==v[b].first ? v[a].second/v[b].second : -1.0);
        }

        return res;
    }
};
