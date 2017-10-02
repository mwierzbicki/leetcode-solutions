// Write a function that takes a string as input and reverse only the vowels of a string.
//
//
// Example 1:
// Given s = "hello", return "holle".
//
//
//
// Example 2:
// Given s = "leetcode", return "leotcede".
//
//
//
// Note:
// The vowels does not include the letter "y".
//


class Solution {
public:
    string reverseVowels(string s) {
        string dict="aeiouAEIOU",vowels="";
        vector<int> pos;
        for (int i=0; i<s.size(); i++) {
            for (int j=0; j<dict.size(); j++) {
                if (s[i]==dict[j]) {
                    pos.push_back(i);
                    vowels+=s[i];
                }
            }
        }
        reverse(vowels.begin(),vowels.end());
        for (int i=0; i<vowels.size(); i++) {
            s[pos[i]]=vowels[i];
        }
        return s;
    }
};
