// Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
//
// You may assume the array's length is at most 10,000.
//
// Example:
//
// Input:
// [1,2,3]
//
// Output:
// 2
//
// Explanation:
// Only two moves are needed (remember each move increments or decrements one element):
//
// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
//
//


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int m,sol=0;
        sort(nums.begin(), nums.end());
        m=nums[nums.size()/2];
        if (!nums.size()%2) {
            m=(m+nums[(nums.size()/2)+1])/2;
        }
        for (int i=0; i<nums.size(); i++) {
            sol+=abs(nums[i]-m);
        }
        return sol;
    }
};
