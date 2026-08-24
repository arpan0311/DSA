class Solution {
public:
    bool isNum(char ch) { return ch >= '0' && ch <= '9'; }
    int calculate(string s) {
        long long sign = 1;
        long long res = 0;
        long long prev = 0;
        stack<long long> st;
        for (int i = 0; i < s.length(); i++) {
            // compute number
            if (isNum(s[i])) {
                prev = prev * 10 + s[i] - '0';
            
            } else if (s[i] == '+' || s[i] == '-') {
                res += sign * prev;
                prev = 0;
                if (s[i] == '+') {
                    sign = 1;
                } else {
                    sign = -1;
                }

            } else if(s[i]=='(') {
                // compute calculation
                st.push(res);
                st.push(sign);
                // form new num
                res = 0;
                prev = 0;
                sign = 1;
            }
            else if(s[i]==')'){
               res+=(sign*prev);
               sign=st.top();st.pop();
               prev=st.top();st.pop();
               res=prev+sign*res;
                prev = 0;
                sign = 1;
            }
        }
        res += sign * prev;
        return res;
    }
};