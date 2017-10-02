// Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.
//
// Note:
//
// Input contains only lowercase English letters.
// Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
// Input length is less than 50,000.
//
//
//
// Example 1:
//
// Input: "owoztneoer"
//
// Output: "012"
//
//
//
// Example 2:
//
// Input: "fviefuro"
//
// Output: "45"
//
//


//old code from round 1b 2016 google code jam
#define t(a) lit[int(a)-97]
class Solution {
public:
    string originalDigits(string s) {
        string dict[10]={"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"}, wyn="";
        //{"zero", "two", "six", "eight", "three", "seven", "four", "five", "nine", "one"}
        int topush[10]={0, 2, 4, 6, 8, 1, 3, 5, 7, 9},lit[26];
        bool ok=false;
        for (int i=0; i<26; i++) {
            lit[i]=0;   
        }
        for (int i=0; i<s.length(); i++) {
            lit[int(s[i]-97)]++;
        }
        for (int i=0; i<10; i++) {
            ok=true;
            for (int j=0; j<dict[i].length(); j++) {
                if (t(dict[i][j])<1) {
                    ok=false;
                }
            }
            if (ok) {
                for (int j=0; j<dict[i].length(); j++) {
                    t(dict[i][j])--;
                }
                wyn+=to_string(topush[i]);
                i--;
            }
        }
        sort(wyn.begin(),wyn.end());
        return wyn;
    }
};
