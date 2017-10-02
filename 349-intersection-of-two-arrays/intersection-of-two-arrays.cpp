//
// Given two arrays, write a function to compute their intersection.
//
//
// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
//
//
// Note:
//
// Each element in the result must be unique.
// The result can be in any order.
//
//


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> b,bb;
        vector<int> sol;
        for (int i=0; i<nums1.size(); i++) {
            b[nums1[i]]=1;
        }
        for (int i=0; i<nums2.size(); i++) {
            if (b[nums2[i]] && !bb[nums2[i]]) {
                sol.push_back(nums2[i]);
                bb[nums2[i]]=1;
            }
        }
        return sol;
    }
};
