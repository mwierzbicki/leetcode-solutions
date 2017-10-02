// Given a roman numeral, convert it to an integer.
//
// Input is guaranteed to be within the range from 1 to 3999.


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> con;
        int ans=0;
        con['I']=1; con['V']=5; con['X']=10; con['L']=50; con['C']=100; con['D']=500; con['M']=1000;
        for (int i=0; i<s.size(); i++) {
            ans+=con[s[i]];
            if (i!=0) {
                if (con[s[i]]>con[s[i-1]]) {
                    ans-=2*con[s[i-1]];
                }
            }
        }
        return ans;
    }
};
