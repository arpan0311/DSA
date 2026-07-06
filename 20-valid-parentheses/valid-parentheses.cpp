class Solution {
public:
    bool isValid(string s) {
      
        if (s[0] == ')' || s[0] == '}' || s[0] == ']') {
            return false;
        }

        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            // left part
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (!st.empty()) {
                    if (s[i] == '}' && st.top() == '{') {
                        st.pop();
                    } else if (s[i] == ')' && st.top() == '(') {
                        st.pop();
                    } else if (s[i] == ']' && st.top() == '[') {
                        st.pop();
                    }
                    else{
                       return false;
                    }

                } 
                else{
                    return false;
                }
            }
        }

        if (st.empty()) {
            return true;
        } 
        return false;
    }
};