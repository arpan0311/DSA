class Solution {
public:
    bool canChange(string s, string t) {
        int n = s.length();

        int i = 0, j = 0;
        while (i < s.length() || j < t.length()) {
            while (i < n && s[i] == '_') {
                i++;
            }

            while (j < n && t[j] == '_') {
                j++;
            }
            if (s[i] != t[j]) {
                return false;
            }

            if (s[i] == 'L' && i < j) {
                return false;
            }
            if (s[i] == 'R' && i > j) {
                return false;
            }
            i++;
            j++;
        }

        

        return true;
    }
};