//
// Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
//


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for (vector<int>::iterator it=nums.begin(); it!=nums.end(); it++) {
            m[*it]++;
            if (m[*it]>1) {
                return true;
            }
        }
        return false;
    }
};
