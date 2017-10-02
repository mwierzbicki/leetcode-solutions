// The set [1,2,3,&#8230;,n] contains a total of n! unique permutations.
//
// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):
//
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
//
//
//
// Given n and k, return the kth permutation sequence.
//
// Note: Given n will be between 1 and 9 inclusive.


class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> p;
        string sol="";
        for (int i=0; i<n; i++) {
            p.push_back(i+1);
        }
        for (int i=0; i<k-1; i++) {
            next_permutation(p.begin(),p.end());
        }
        for (int i=0; i<n; i++) {
            sol+=to_string(p[i]);
        }
        return sol;
    }
};
