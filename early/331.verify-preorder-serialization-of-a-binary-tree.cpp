/*
 * [331] Verify Preorder Serialization of a Binary Tree
 *
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree
 *
 * Medium (35.85%)
 * Total Accepted:    34610
 * Total Submissions: 96543
 * Testcase Example:  '"9,3,4,#,#,1,#,#,2,#,6,#,#"'
 *
 * One way to serialize a binary tree is to use pre-order traversal. When we
 * encounter a non-null node, we record the node's value. If it is a null node,
 * we record using a sentinel value such as #.
 * 
 * 
 * ⁠    _9_
 * ⁠   /   \
 * ⁠  3     2
 * ⁠ / \   / \
 * ⁠4   1  #  6
 * / \ / \   / \
 * # # # #   # #
 * 
 * 
 * For example, the above binary tree can be serialized to the string
 * "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 * 
 * 
 * Given a string of comma separated values, verify whether it is a correct
 * preorder traversal serialization of a binary tree. Find an algorithm without
 * reconstructing the tree.
 * 
 * Each comma separated value in the string must be either an integer or a
 * character '#' representing null pointer.
 * 
 * You may assume that the input format is always valid, for example it could
 * never contain two consecutive commas such as "1,,3".
 * 
 * Example 1:
 * "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Return true
 * Example 2:
 * "1,#"
 * Return false
 * Example 3:
 * "9,#,#,1"
 * Return false
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> s;
        if(preorder.size() < 2){
            return preorder == "#";
        }
        
        bool lastChar = false;
        for(size_t i=0;i != preorder.size();i++){
            char c = preorder.at(i);
            if(c==','){
                lastChar = false;
                continue;
            }
           
            if(lastChar){
                continue;
            }
            lastChar = true;
             
            if(c!='#'){
                if(i && s.empty()){
                    return false;
                }
                s.push(0);
                continue;
            }
            
            if(s.empty()){
                return false;
            }
            
            while(!s.empty()){
                int val = s.top();
                s.pop();
                val++;
                if(val != 2){
                    s.push(val);
                    break;
                }
            }
            
        }
        
        return s.empty();
    }
};
