/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (49.50%)
 * Likes:    4183
 * Dislikes: 191
 * Total Accepted:    435.4K
 * Total Submissions: 865.5K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Clarification: The input/output format is the same as how LeetCode
 * serializes a binary tree. You do not necessarily need to follow this format,
 * so please be creative and come up with different approaches yourself.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 * Example 4:
 *
 *
 * Input: root = [1,2]
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) {
      return "";
    }

    vector<TreeNode*> lvl[2];
    int index = 0;
    lvl[index].push_back(root);

    string s;

    const int kNull = INT_MIN;
    while (!lvl[index].empty()) {
      int count = lvl[index].size();
      s.reserve(s.size() + (count + 1) * sizeof(int));
      s.append((const char*)&count, sizeof(count));
      auto& next_lvl = lvl[1 - index];
      next_lvl.clear();
      for (auto p : lvl[index]) {
        if (p != nullptr) {
          next_lvl.push_back(p->left);
          next_lvl.push_back(p->right);
        }

        s.append((const char*)(p ? &p->val : &kNull), sizeof(int));
      }
      index = 1 - index;
    }

    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.empty()) {
      return nullptr;
    }

    const int kNull = INT_MIN;
    TreeNode* root = nullptr;
    vector<TreeNode*> lvl[2];
    const char* start = data.data();
    const char* end = start + data.size();
    for (int index = 0; start < end; index = 1 - index) {
      int num;
      memcpy((void*)&num, start, sizeof(int));
      start += sizeof(int);
      auto& last_lvl = lvl[1 - index];
      auto& cur_lvl = lvl[index];
      cur_lvl.clear();
      for (int i = 0; i < num; i++) {
        int val;
        memcpy(&val, start, sizeof(int));
        start += sizeof(int);
        if (val == kNull) {
          continue;
        }

        TreeNode* p = new TreeNode(val);
        if (root == nullptr) {
          root = p;
        } else {
          if (i & 1) {
            last_lvl[i / 2]->right = p;
          } else {
            last_lvl[i / 2]->left = p;
          }
        }

        cur_lvl.push_back(p);
      }
    }

    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
