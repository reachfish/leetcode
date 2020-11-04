/*
 * [661] Image Smoother
 *
 * https://leetcode.com/problems/image-smoother
 *
 * algorithms
 * Easy (47.44%)
 * Total Accepted:    4.3K
 * Total Submissions: 9K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a 2D integer matrix M representing the gray scale of an image, you
 * need to design a smoother to make the gray scale of each cell becomes the
 * average gray scale (rounding down) of all the 8 surrounding cells and
 * itself.  If a cell has less than 8 surrounding cells, then use as many as
 * you can.
 * 
 * Example 1:
 * 
 * Input:
 * [[1,1,1],
 * ⁠[1,0,1],
 * ⁠[1,1,1]]
 * Output:
 * [[0, 0, 0],
 * ⁠[0, 0, 0],
 * ⁠[0, 0, 0]]
 * Explanation:
 * For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
 * For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
 * For the point (1,1): floor(8/9) = floor(0.88888889) = 0
 * 
 * 
 * 
 * Note:
 * 
 * The value in the given matrix is in the range of [0, 255].
 * The length and width of the given matrix are in the range of [1, 150].
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		if(M.empty() || M[0]. empty()){
			return vector<vector<int>>();
		}

		int m = M.size();        
		int n = M[0].size();

		vector<vector<int>> res(m, vector<int>(n));
		for(int i=0; i<m; i++){
			for(int j=0;j<n; j++){
				int sum = 0;
				int count = 0;
				for(int r=-1;r<=1; r++){
					for(int s=-1;s<=1; s++){
						int p = i + r;
						int q = j + s;
						if(p>=0&&p<m&&q>=0&&q<n){
							sum += M[p][q];
							count++;
						}
					}
				}
				res[i][j] = sum/count;
			}
		}

		return res;
    }
};
