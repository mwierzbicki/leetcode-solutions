// Given numRows, generate the first numRows of Pascal's triangle.
//
//
// For example, given numRows = 5,
// Return
//
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> sol;
        vector<int> t;
        if (numRows==0) {
            return sol;
        }
        t.push_back(1);
        sol.push_back(t);
        for (int i=1; i<numRows; i++) {
            t.clear();
            t.push_back(1);
            for (int j=1; j<sol[i-1].size(); j++) {
                t.push_back(sol[i-1][j]+sol[i-1][j-1]);
            }
            t.push_back(1);
            sol.push_back(t);
        }
        return sol;
    }
};
