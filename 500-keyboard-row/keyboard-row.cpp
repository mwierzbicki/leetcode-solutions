// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below. 
//
//
//
//
//
//
//
// Example 1:
//
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
//
//
//
// Note:
//
// You may use one character in the keyboard more than once.
// You may assume the input string will only contain letters of alphabet.
//
//


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> sol;
        const string d[3]={"QWERTYUIOPqwertyuiop","ASDFGHJKLasdfghjkl","ZXCVBNMzxcvbnm"};
        int t[3];
        map<char,int> cnt;
        for (int i=0; i<words.size(); i++) {
            cnt.clear();
            for (int j=0; j<words[i].size(); j++) {
                cnt[words[i][j]]++;
            }
            for (int k=0; k<3; k++) {
                t[k]=0;
                for (int j=0; j<d[k].size(); j++) {
                    t[k]+=cnt[d[k][j]];
                }
            }
            if (min(t[0],t[1])==0 && min(t[1],t[2])==0 && min(t[0],t[2])==0) {
                sol.push_back(words[i]);
            }
        }
        return sol;
    }
};
