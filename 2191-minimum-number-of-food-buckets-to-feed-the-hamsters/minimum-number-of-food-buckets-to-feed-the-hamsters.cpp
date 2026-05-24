class Solution {
public:
    int minimumBuckets(string s) {
        int cnt = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != 'H') {
                continue;
            }
            if (i - 1 >= 0 && s[i - 1] == 'V') {
                continue;
            }

            else if (i + 1 < s.length() && s[i + 1] == '.') {
                s[i + 1] = 'V';
                cnt++;
            } else if (i - 1 >= 0 && s[i - 1] == '.') {
                s[i - 1] = 'V';
                cnt++;
            } else {
                return -1;
            }
        }
        return cnt;
    }
};