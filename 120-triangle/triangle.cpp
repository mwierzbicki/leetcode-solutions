// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
//
// For example, given the following triangle
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
//
//
//
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//
//
// Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
//


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int mmin=2147483647,ts=triangle.size()-1;
        for (int i=1; i<=ts; i++) {
            triangle[i][0]+=triangle[i-1][0];
            triangle[i][i]+=triangle[i-1][i-1];
            for (int j=1; j<i; j++) {
                triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }
        for (int i=0; i<=ts; i++) {
            mmin=min(mmin,triangle[ts][i]);
        }
        return mmin;
    }
};
