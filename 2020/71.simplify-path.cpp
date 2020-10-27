/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (33.18%)
 * Likes:    938
 * Dislikes: 1949
 * Total Accepted:    228.3K
 * Total Submissions: 688.2K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it. Or in other
 * words, convert it to the canonical path.
 * 
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level.
 * 
 * Note that the returned canonical path must always begin with a slash /, and
 * there must be only a single slash / between two directory names. The last
 * directory name (if it exists) must not end with a trailing /. Also, the
 * canonical path must be the shortest string representing the absolute
 * path.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "/a/./b/../../c/"
 * Output: "/c"
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "/a/../../b/../c//.//"
 * Output: "/c"
 * 
 * 
 * Example 6:
 * 
 * 
 * Input: "/a//b////c/d//././/.."
 * Output: "/a/b/c"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vp;
        int s = -1;
        int e = -1;

        auto push_directory = [&]() {
            if (s == -1) {
                return;
            }

            if (path[e] == '.') {
                if (s + 1 == e && path[s] == '.') {
                    if (!vp.empty()) {
                        vp.pop_back();
                    }
                } else if (s != e) {
                    vp.emplace_back((const char*)(path.c_str() + s), (size_t)(e - s + 1));
                }
            } else {
                vp.emplace_back((const char*)(path.c_str() + s), (size_t)(e - s + 1));
            }

            s = -1;
        };

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                push_directory();
            } else {
                if (s == -1) {
                    s = i;
                }
                e = i;
            }
        }
        push_directory();

        std::string str;
        for (const auto& d : vp) {
            str += "/" + d;
        }

        if (str.empty()) {
            str = "/";
        }

        return str;
    }
};
// @lc code=end
