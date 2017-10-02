//
// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//
//
// click to show follow up.
//
// Follow up:
//
//
// Did you use extra space?
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?
//
//


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> x,y;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                if (matrix[i][j]==0) {
                    x.push_back(j);
                    y.push_back(i);
                }
            }
        }
        for (int k=0; k<x.size(); k++) {
            for (int i=0; i<matrix.size(); i++) {
                matrix[i][x[k]]=0;
            }
            for (int i=0; i<matrix[0].size(); i++) {
                matrix[y[k]][i]=0;
            }
        }
    }
};
