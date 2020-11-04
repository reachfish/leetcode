/*
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum
 *
 * Medium (52.00%)
 * Total Accepted:    13369
 * Total Submissions: 25712
 * Testcase Example:  '[5,2,-3]'
 *
 * 
 * Given the root of a tree, you are asked to find the most frequent subtree
 * sum. The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself). So
 * what is the most frequent subtree sum value? If there is a tie, return all
 * the values with the highest frequency in any order.
 * 
 * 
 * Examples 1
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -3
 * 
 * return [2, -3, 4], since all the values happen only once, return all of them
 * in any order.
 * 
 * 
 * Examples 2
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -5
 * 
 * return [2], since 2 happens twice, however -5 only occur once.
 * 
 * 
 * Note:
 * You may assume the sum of values in any subtree is in the range of 32-bit
 * signed integer.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void find(TreeNode* p, int &sum, map<int, int>& m){
        if(!p){
            sum = 0;
            return;
        }
        
        int s1, s2;
        find(p->left, s1, m);
        find(p->right, s2, m);
        
        sum = p->val + s1 + s2;
        m[sum]++;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> m;
        int sum;
        find(root, sum, m);
        
        int max = 0;
        vector<int> res;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>=max){
                if(it->second > max){
                    max = it->second;
                    res.clear();
                }
                
                res.push_back(it->first);
            }
        }
        
        return res;
    }
};
