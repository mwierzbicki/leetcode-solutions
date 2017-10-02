//
// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//
//
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
//
//
// Some examples:
//
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//
//


class Solution {
int a,b;
stack<int> liczby;
public:
    void getnumbers() {
        b=liczby.top();
        liczby.pop();
        a=liczby.top();
        liczby.pop();
    }
    int evalRPN(vector<string>& tokens) {
        for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
            if (*it=="+") {
                getnumbers();
                liczby.push(a+b);
            }
            else if (*it=="-") {
                getnumbers();
                liczby.push(a-b);                
            }
            else if (*it=="*") {
                getnumbers();
                liczby.push(a*b);                
            }
            else if (*it=="/") {
                getnumbers();
                liczby.push(a/b);                
            }
            else {
                liczby.push(stoi(*it));
            }
        }
        return liczby.top();
    }
};
