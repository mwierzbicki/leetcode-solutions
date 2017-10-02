//
// Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once. 
//
//
// Example 1:
//
// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
//
//
//
// Example 2:
//
// Input: [3,3,7,7,10,11,11]
// Output: 10
//
//
//
// Note:
// Your solution should run in O(log n) time and O(1) space.
//
//


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0, end=nums.size()-1, center;
        while(start<end) {
            center=(start+end+1)/2;
            if (center>0 && nums[center]==nums[center-1]) {
                if (center%2) start=center+1;
                else end=center-1;
            }
            else if (center<nums.size()-1 && nums[center]==nums[center+1]) {
                if (center%2) end=center-1;
                else start=center+1;
            }
            else {
                return nums[center];
            }
        }
        return nums[start];
    }
};
