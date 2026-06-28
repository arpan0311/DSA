class Solution {
public:
    bool solve(vector<int>& a, vector<int>& b) {
        int i = 0;
        while (i < a.size()) {
            // agar 0 frequency hai to bhada do..
            if (a[i] == 0) {
                i++;
                continue;
            }
            if (a[i] > b[i]) {
                return false;
            }
            i++;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if (t.length() > s.length()) {
            return "";
        }
        vector<int> a(256, 0);
        for (int i = 0; i < t.size(); i++) {
            a[t[i]]++;
        }
        int n = s.length();
        int s1 = -1;
        int i = 0, j = 0;
        int len = INT_MAX;
        vector<int> b(256, 0);
        while (j < s.length()) {
            b[s[j]]++;
            while (i <= j && solve(a, b)) {
                if (j - i + 1 < len) {
                    len = j - i + 1;
                    s1 = i;
                }
                b[s[i]]--;
                i++;
            }
            j++;
        }
        if(s1==-1){
            return "";
        }
        return s.substr(s1, len);
    }
};