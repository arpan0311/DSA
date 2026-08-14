class Solution {
public:
    int maximumLengthSubstring(string s) {
        int len = 0;
        for (int i = 0; i < s.length(); i++) {
            vector<int> frec(26, 0);
            for (int j = i; j < s.length(); j++) {
                frec[s[j] - 'a']++;
                int maxi = *max_element(frec.begin(), frec.end());
                if (maxi <= 2) {
                    len = max(len, j - i + 1);
                }
            }
        }
        return len;
    }
};