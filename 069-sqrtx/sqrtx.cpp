// Implement int sqrt(int x).
//
// Compute and return the square root of x.


class Solution {
public:
    int mySqrt(int num) {
        int sta=0, end=46340, mid;
        while (sta<end) {
            mid=(sta+end+1)/2;
            if (mid*mid>num) {
                end=mid-1;
            }
            else {
                sta=mid;
            }
        }
        return sta;
    }
};
