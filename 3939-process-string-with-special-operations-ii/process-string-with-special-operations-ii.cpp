class Solution {
public:
    char processStr(string s, long long k) {

        long long L = 0;

        for (char ch : s) {
            if ('a' <= ch && ch <= 'z') {
                L++;
            }
            else if (ch == '*') {
                if (L > 0) L--;
            }
            else if (ch == '#') {
                L *= 2;
            }
        }

        if (k >= L) return '.';

        int n = s.size();

        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '*') {
                L++;                    // no change in k
            }
            else if (s[i] == '%') {
                k = L - k - 1;
            }
            else if (s[i] == '#') {
                L /= 2;
                if (k >= L) {
                    k -= L;
                }
            }
            else { // lowercase letter

                L--;

                if (k == L) {
                    return s[i];
                }
            }
        }

        return '.';
    }
};