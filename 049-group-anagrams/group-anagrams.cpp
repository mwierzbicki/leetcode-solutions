// Given an array of strings, group anagrams together.
//
//
// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
// Return:
//
// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note: All inputs will be in lower-case.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > sol;
        string t;
        unordered_map<string,vector<string> > h;
        unordered_map<string,bool> hh;
        for (vector<string>::iterator it=strs.begin(); it!=strs.end(); it++) {
            t=*it;
            sort(t.begin(),t.end());
            h[t].push_back(*it);
        }
        for (vector<string>::iterator it=strs.begin(); it!=strs.end(); it++) {
            t=*it;
            sort(t.begin(),t.end());
            if (!hh[t]) {
                sol.push_back(h[t]);
            }
            hh[t]=1;
        }
        return sol;
    }
};
