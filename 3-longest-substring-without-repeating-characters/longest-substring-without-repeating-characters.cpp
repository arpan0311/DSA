class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> can_do(256, -1);
        int i = 0;
        int max_len = 0;
        for (int j = 0; j < s.size(); j++) {
            // means phale se hai
            if (can_do[s[j]] != -1) {
                if (can_do[s[j]] >= i) {
                    i = can_do[s[j]] + 1;
                }
            }
            int curr_len = j - i + 1;
            max_len = max(max_len, curr_len);
            can_do[s[j]]=j;
        }
        return max_len;
    }
};