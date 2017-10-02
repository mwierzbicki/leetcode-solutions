//
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//
// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//
//
// Your algorithm should run in O(n) complexity.
//


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> a; 
        int r=0,sol=0;
        for (int i=0; i<nums.size(); i++) {
            a.insert(nums[i]);
        }
        for (int i=0; i<nums.size(); i++) {
            if (!a.count(nums[i]-1)) {
                r=1;
                while (a.count(nums[i]+r)) {
                    r++;
                }
            }
            sol=max(sol,r);
        }
        a.clear();
        return sol;
    }
};
