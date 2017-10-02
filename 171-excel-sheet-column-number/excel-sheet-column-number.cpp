// Related to question Excel Sheet Column Title
// Given a column title as appear in an Excel sheet, return its corresponding column number.
//
// For example:
//     A -&gt; 1
//     B -&gt; 2
//     C -&gt; 3
//     ...
//     Z -&gt; 26
//     AA -&gt; 27
//     AB -&gt; 28 
//
// Credits:Special thanks to @ts for adding this problem and creating all test cases.


class Solution {
public:
    int titleToNumber(string s) {
        long long pot=1,wyn=0;
        for (int i=s.size()-1; i>=0; i--) {
            wyn=wyn+((int(s[i])-64)*pot);
            pot=pot*26;
        }
        return wyn;
    }
};
