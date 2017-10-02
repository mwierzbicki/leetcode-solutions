//
// Implement strStr().
//
//
// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//


class Solution {
public:
    int strStr(string haystack, string needle) {
        string s=" "+needle+"#"+haystack;
        if (needle.size()==0) {
            return 0;
        }
        if (haystack.size()==0) {
            return -1;
        }
        vector<int> p(s.size()+1,0);
        int t=0;
        for (int i=2; i<=s.size(); i++) {
            while (t>0 && s[t+1]!=s[i]) {
                t=p[t];
            }
            if (s[t+1]==s[i]) {
                t++;
            }
            p[i] = t;
            if (p[i]==needle.size()) {
                return i-(2*needle.size())-1;
            }
        }
        return -1;
    }
};
