//
// Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:
//
// The number at the ith position is divisible by i.
// i is divisible by the number at the ith position.
//
//
//
//
// Now given N, how many beautiful arrangements can you construct?
//
//
// Example 1:
//
// Input: 2
// Output: 2
// Explanation: 
// The first beautiful arrangement is [1, 2]:
// Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
// Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
// The second beautiful arrangement is [2, 1]:
// Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
// Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
//
//
//
// Note:
//
// N is a positive integer and will not exceed 15.
//
//


class Solution {
int wyn=0,gn;
public:
    int countArrangement(int N) {
        gn=N;
        bool bylo[gn+1];
        for (int i=1; i<=gn; i++) {
            bylo[i]=0;
        }
        check(1,bylo);
        return wyn;
    }
    void check(int pos, bool bylo[]) {
        for (int i=1; i<=gn; i++) {
            if ((pos%i==0 || i%pos==0) && !bylo[i]) {
                bylo[i]=1;
                if (pos<gn) {
                    check(pos+1,bylo);
                }
                else {
                    wyn++;
                }
                bylo[i]=0;
            }
        }
        return;
    }
};
