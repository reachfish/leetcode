/*
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area
 *
 * Medium (32.60%)
 * Total Accepted:    60882
 * Total Submissions: 186754
 * Testcase Example:  '-2\n-2\n2\n2\n-2\n-2\n2\n2'
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * Each rectangle is defined by its bottom left corner and top right corner as
 * shown in the figure.
 * 
 * 
 * 
 * 
 * Assume that the total area is never beyond the maximum possible value of
 * int.
 * 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem, creating the
 * above image and all test cases.
 */
class Solution {
public:
    void normal(int &a, int &b){
        if(a<=b){
            return;
        }
        
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    int getLen(int a1, int a2, int b1, int b2){
        if(b1>=a2||b2<=a1){
            return 0;
        }    
        
        return (a2<b2 ? a2:b2) - (a1>b1? a1:b1);
    }
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        normal(A, C);
        normal(B, D);
        normal(E, G);
        normal(F, H);
        
        return (C-A)*(D-B) + (G-E)*(H-F) - getLen(A, C, E, G) * getLen(B, D, F, H);
    }
};
