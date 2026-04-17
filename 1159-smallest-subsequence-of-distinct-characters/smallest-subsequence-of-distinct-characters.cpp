class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        stack<char> st;
        unordered_set<char> used;

        for (char c : s) {
            freq[c]--;  // current char processed

            // if already in stack → skip
            if (used.count(c)) continue;

            // maintain lexicographical order
            while (!st.empty() && st.top() > c && freq[st.top()] > 0) {
                used.erase(st.top());
                st.pop();
            }

            st.push(c);
            used.insert(c);
        }

        // build answer
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
  
    }
};