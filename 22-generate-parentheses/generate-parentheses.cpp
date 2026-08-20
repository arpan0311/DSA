class Solution {
public:
    int size;
    bool isvalid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                if (s[i] == '(') {
                    st.push(s[i]);
                } else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }

    void solve(string s, int n, int m, vector<string>& answer) {

        if (s.length() == size) {
            if (isvalid(s)) {
                answer.push_back(s);
            }
            return ;
        }

        if (n > 0) {
            s.push_back('(');
            solve(s, n - 1, m, answer);
            s.pop_back();
        }

        if (m > 0) {
            s.push_back(')');
            solve(s, n, m - 1, answer);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        size = 2 * n;
        int n1=n;
        string s = "";
        vector<string> answer;

        solve(s, n, n1, answer);

        return answer;
    }
};