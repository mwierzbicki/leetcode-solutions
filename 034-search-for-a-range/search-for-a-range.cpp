// Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
//
// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].
//


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> sol;
        if (binary_search(nums.begin(),nums.end(),target)) {
            sol.push_back(lower_bound(nums.begin(),nums.end(),target)-nums.begin());
            sol.push_back(upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1);
        }
        else {
            sol.push_back(-1);
            sol.push_back(-1);
        }
        return sol;
    }
};
