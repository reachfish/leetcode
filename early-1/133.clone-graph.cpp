/*
 * [133] Clone Graph
 *
 * https://leetcode.com/problems/clone-graph
 *
 * Medium (25.08%)
 * Total Accepted:    109480
 * Total Submissions: 436450
 * Testcase Example:  '{}'
 *
 * 
 * Clone an undirected graph. Each node in the graph contains a label and a
 * list of its neighbors.
 * 
 * 
 * 
 * 
 * OJ's undirected graph serialization:
 * 
 * 
 * Nodes are labeled uniquely.
 * 
 * 
 * We use # as a separator for each node, and , as a separator for node label
 * and each neighbor of the node.
 * 
 * 
 * 
 * 
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 * 
 * 
 * 
 * The graph has a total of three nodes, and therefore contains three parts as
 * separated by #.
 * 
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming
 * a self-cycle.
 * 
 * 
 * 
 * 
 * Visually, the graph looks like the following:
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    /   \
 * ⁠   0 --- 2
 * ⁠        / \
 * ⁠        \_/
 * 
 * 
 * 
 * 
 */
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    
    UndirectedGraphNode* getClone(map<int, UndirectedGraphNode*> &m, UndirectedGraphNode *p){
        if(!p){
            return NULL;
        }
        
        int label = p->label;
        if(m.count(label)){
            return m[label];
        }
        
        UndirectedGraphNode* node = new UndirectedGraphNode(label);

        m[label] = node;
        for(int i=0;i<p->neighbors.size();i++){
            node->neighbors.push_back(getClone(m, p->neighbors[i]));    
        }
        
        return node;
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int, UndirectedGraphNode *> m;
        
        return getClone(m, node);
    }
};
