//
// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//
//
// For example,
// [1,1,2] have the following unique permutations:
//
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > sol;
        sort(nums.begin(),nums.end());
        do {
            sol.push_back(nums);
        } while (next_permutation(nums.begin(),nums.end()));
        return sol;
    }
};
