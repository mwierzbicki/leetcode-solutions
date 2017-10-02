//
// Given an unsorted array of integers, find the length of longest increasing subsequence.
//
//
// For example,
// Given [10, 9, 2, 5, 3, 7, 101, 18],
// The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
//
//
// Your algorithm should run in O(n2) complexity.
//
//
// Follow up: Could you improve it to O(n log n) time complexity? 
//
// Credits:Special thanks to @pbrother for adding this problem and creating all test cases.


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int soll=0;
        vector<int> sol;
        sol.push_back(1);
        for (int i=1; i<nums.size(); i++) {
            sol.push_back(1);
            for (int j=0; j<i; j++) {
                if (nums[j]<nums[i]) {
                    sol[i]=max(sol[i],sol[j]+1);
                }
            }
        }
        for (int i=0; i<nums.size(); i++) {
            soll=max(soll,sol[i]);
        }
        return soll;
    }
};
