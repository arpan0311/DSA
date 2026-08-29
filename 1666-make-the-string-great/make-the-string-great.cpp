class Solution {
public:
    string makeGood(string s) {

        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (ans.empty()) {
                ans.push_back(s[i]);
            } else {
                if (isupper(s[i])) {
                    if (ans.back() == tolower(s[i])) {
                        ans.pop_back();
                    } else {
                        ans.push_back(s[i]);
                    }
                } else {
                    if (ans.back() == toupper(s[i])) {
                        ans.pop_back();
                    } else {
                        ans.push_back(s[i]);
                    }
                }
            }
        }
        return ans;
    }
};