// Implement pow(x, n).
//


class Solution {
public:
    double myPow(double x, int n) {
        double wyn=1;
        unsigned long long nn;
        if (n<0) {
            nn=-n;
            x=1/x;
        }
        else {
            nn=n;
        }
        while (nn) {
            if (nn%2) {
                wyn=wyn*x;
            }
            nn/=2;
            x=x*x;
        }
        return wyn;
    }
};
