// Reverse digits of an integer.
//
//
// Example1: x =  123, return  321
// Example2: x = -123, return -321
//
//
// click to show spoilers.
//
// Have you thought about this?
//
// Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
//
// If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
//
// Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
//
// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//
//
//
//
//
// Note:
// The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
//


class Solution {
public:
    int reverse(int x) {
        bool f=0;
        if (x<0) {
            f=1;
            x=-x;
        }
        vector<long long> s;
        long long sol=0,p=1;
        while (x>0) {
            s.push_back(x%10);
            x-=x%10;
            x/=10;
        }
        for (int i=s.size()-1; i>=0; i--) {
            sol=sol+(p*s[i]);
            p=p*10;
        }
        if (f) {
            sol=-sol;
        }
        if (sol>INT_MAX || sol<INT_MIN) {
            sol=0;
        }
        return sol;
    }
};
