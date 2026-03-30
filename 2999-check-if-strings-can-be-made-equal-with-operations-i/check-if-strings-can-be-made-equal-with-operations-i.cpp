class Solution {
public:
    bool canBeEqual(string s1, string s2) {

        int k = 3;
        while (k >= 0) {
            int i = 0;
            while (i + 2 < s1.length()) {
                if (s1[i] != s2[i]) {
                    swap(s1[i], s1[i + 2]);
                }
                i++;
            }
            if (s1 == s2) {
                return true;
            }
            k--;
        }
        return false;
    }
};