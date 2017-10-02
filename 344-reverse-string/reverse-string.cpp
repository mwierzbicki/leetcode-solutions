// Write a function that takes a string as input and returns the string reversed.
//
//
// Example:
// Given s = "hello", return "olleh".
//


class Solution {
public:
    string reverseString(string s) {
        for (int i=0; i<s.size()/2; i++) {
            swap(s[i],s[s.size()-i-1]);
        }
        return s;
    }
};
