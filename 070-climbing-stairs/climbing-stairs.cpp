// You are climbing a stair case. It takes n steps to reach to the top.
//
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//
//
// Note: Given n will be a positive integer.
//


//o(log n) solution using fast matrix multiplication
class Solution {
public:
    struct M {
        int a,b,c,d;  
    };
    M multiplyMatrix(M a, M b) {
        M ret;
        ret.a=a.a*b.a+a.b*b.c;
        ret.b=a.a*b.b+a.b*b.d;
        ret.c=a.c*b.a+a.d*b.c;
        ret.d=a.c*b.b+a.d*b.d;
        return ret;
    }
    long long getAns(int n) {
        M fib,ans;
        fib.a=0,fib.b=1,fib.c=1,fib.d=1;
        ans=fib;
        while (n>0) {
            if (n%2) {
                ans=multiplyMatrix(ans,fib);
            }
            fib=multiplyMatrix(fib,fib);
            n/=2;
        }
        return ans.d;
    }
    int climbStairs(int n) {
        if (n<3) {
            return max(0,n);
        }
        return getAns(n-1);
    }
};
