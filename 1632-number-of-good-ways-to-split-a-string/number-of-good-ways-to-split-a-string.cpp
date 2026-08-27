class Solution {
public:
    int numSplits(string s) {
        vector<int> prefix(s.length(), 0);

        unordered_set<char> st;

        for (int i = s.length() - 1; i >= 0; i--) {
            st.insert(s[i]);
            prefix[i] = st.size();
        }

        int cnt = 0;
        unordered_set<char> st1;
        // st1.insert(s[0]);
        for (int i = 0; i < s.length() - 1; i++) {
            st1.insert(s[i]);
            if (st1.size() == prefix[i + 1]) {
                cnt++;
            }
        }
        return cnt;
    }
};