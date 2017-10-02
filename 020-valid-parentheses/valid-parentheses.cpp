// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='(') {
                st.push(')');
            }
            else if (s[i]=='[') {
                st.push(']');
            }
            else if (s[i]=='{') {
                st.push('}');
            }
            else {
                if (st.empty()) {
                    return false;
                }
                else {
                    if (st.top()!=s[i]) {
                        return false;
                    }
                    else {
                        st.pop();
                    }
                }
            }
        }
        if (st.size()>0) {
            return false;
        }
        return true;
    }
};
