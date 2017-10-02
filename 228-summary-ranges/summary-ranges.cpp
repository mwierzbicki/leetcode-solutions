//
// Given a sorted integer array without duplicates, return the summary of its ranges.
//
// Example 1:
//
// Input: [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
//
//
//
// Example 2:
//
// Input: [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
//
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> sol;
        if (nums.size()==0) {
            return sol;
        }
        int start=nums[0],end=nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]-1==end) {
                end=nums[i];
            }
            else {
                if (start==end) {
                    sol.push_back(to_string(start));
                }
                else {
                    sol.push_back(to_string(start)+"->"+to_string(end));
                }
                start=nums[i];
                end=nums[i];
            }
        }
        if (start==end) {
            sol.push_back(to_string(start));
        }
        else {
            sol.push_back(to_string(start)+"->"+to_string(end));
        }
        return sol;
    }
};
