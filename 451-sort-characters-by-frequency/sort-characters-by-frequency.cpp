// Given a string, sort it in decreasing order based on the frequency of characters.
//
// Example 1:
//
// Input:
// "tree"
//
// Output:
// "eert"
//
// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
//
//
//
// Example 2:
//
// Input:
// "cccaaa"
//
// Output:
// "cccaaa"
//
// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
//
//
//
// Example 3:
//
// Input:
// "Aabb"
//
// Output:
// "bbAa"
//
// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
//
//


//time complexity: (c - number of unique chars) O(s + c log c)
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> f;
        vector<pair<int,char> > ts;
        string sol="";
        for (int i=0; i<s.size(); i++) {
            f[s[i]]++;
        }
        for (int i=0; i<s.size(); i++) {
            if (f[s[i]]>0) {
                ts.push_back(make_pair(f[s[i]],s[i]));
                f[s[i]]=0;
            }
        }
        sort(ts.begin(),ts.end(),greater<pair<int,char> >());
        for (int i=0; i<ts.size(); i++) {
            for (int j=0; j<ts[i].first; j++) {
                sol+=ts[i].second;
            }
        }
        return sol;
    }
};
