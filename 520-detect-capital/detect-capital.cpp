//
// Given a word, you need to judge whether the usage of capitals in it is right or not.
//
//
//
// We define the usage of capitals in a word to be right when one of the following cases holds:
//
// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital if it has more than one letter, like "Google".
//
// Otherwise, we define that this word doesn't use capitals in a right way.
//
//
//
// Example 1:
//
// Input: "USA"
// Output: True
//
//
//
// Example 2:
//
// Input: "FlaG"
// Output: False
//
//
//
// Note:
// The input will be a non-empty word consisting of uppercase and lowercase latin letters.
//


//lazy flow control
class Solution {
public:
    bool detectCapitalUse(string word) {
        vector<bool> wyn;
        bool fail=0;
        for (int i=0; i<word.size(); i++) {
            wyn.push_back(int(word[i])<97);
        }
        if (wyn.size()>1) {
            if (wyn[0]) {
                if (wyn[1]) {
                    for (int i=1; i<wyn.size(); i++) {
                        if (!wyn[i]) {
                                fail=1;
                            }
                        }
                    }
                else {
                    for (int i=1; i<wyn.size(); i++) {
                        if (wyn[i]) {
                            fail=1;
                        }
                    }
                }
            }
            else {
                for (int i=1; i<wyn.size(); i++) {
                    if (wyn[i]) {
                        fail=1;
                    }
                }
            }
        }
        return !fail;
    }
};
