// Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
//
// You may assume the integer do not contain any leading zero, except the number 0 itself.
//
// The digits are stored such that the most significant digit is at the head of the list.


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int wsk=digits.size()-1;
        bool add=0;
        while (wsk!=-1) {
            if (digits[wsk]==9) {
                digits[wsk]=0;
                if (wsk==0) {
                    add=1;
                }
                wsk--;
            }
            else {
                digits[wsk]++;
                wsk=-1;
            }
        }
        if (add) {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
