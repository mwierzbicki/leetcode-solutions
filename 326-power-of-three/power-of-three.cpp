//
//     Given an integer, write a function to determine if it is a power of three.
//
//
//     Follow up:
//     Could you do it without using any loop / recursion?
//
//
// Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.


class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n==0 || n<0) {
            return false;
        }
        if (n==1) {
            return true;
        }
        while (n>1) {
            if (n%3) {
                return false;
            }
            n/=3;
        }
        return true;
    }
};
