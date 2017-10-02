// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1. 
//
//
// Example 1:
//
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
//
//
//
// Example 2:
//
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
//
//
//
// Note:
// The length of the given binary array will not exceed 50,000.
//


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int wynik=0,maxlew=50002,maxpraw=0,licz=0;
        vector<pair<int,int> > wyn;
        wyn.push_back(make_pair(0,0));
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]) {
                licz++;
            }
            else {
                licz--;
            }
            wyn.push_back(make_pair(licz,i+1));
        }
        sort(wyn.begin(),wyn.end());
        for (int i=0; i<wyn.size()-1; i++) {
            if (wyn[i].first==wyn[i+1].first) {
                maxlew=min(maxlew,min(wyn[i].second,wyn[i+1].second));
                maxpraw=max(maxpraw,max(wyn[i].second,wyn[i+1].second));
                wynik=max(wynik,maxpraw-maxlew);
            }
            else {
                maxlew=50002;
                maxpraw=0;
            }
        }
        return wynik;
    }
};
