// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
//
// This is case sensitive, for example "Aa" is not considered a palindrome here.
//
// Note:
// Assume the length of given string will not exceed 1,010.
//
//
// Example: 
//
// Input:
// "abccccdd"
//
// Output:
// 7
//
// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.
//
//


class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> cnt;
        int sol=0;
        bool add=0;
        for (int i=0; i<s.size(); i++) {
            cnt[s[i]]++;
        }
        for (char i='A'; i<='Z'; i++) {
            if (cnt[i]%2==1) {
                add=1;
            }
            sol+=cnt[i]-(cnt[i]%2);
        }
        for (char i='a'; i<='z'; i++) {
            if (cnt[i]%2==1) {
                add=1;
            }
            sol+=cnt[i]-(cnt[i]%2);
        }
        return sol+add;
    }
};
