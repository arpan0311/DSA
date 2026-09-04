class Solution {
public:
    string res = "";

    bool solve(string& curr, string& target, vector<int>& mp, int i,
               bool can_do) {

        if (i == target.size()) {
            if (can_do) {
                res = curr;
                return true;
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {

            if (mp[ch - 'a'] == 0) {
                continue;
            }

            if (!can_do && ch < target[i]) {
                continue;
            }

            curr.push_back(ch);
            mp[ch - 'a']--;

            bool is_can_do = can_do || (ch > target[i]);

            if (solve(curr, target, mp, i + 1, is_can_do)) {
                return true;
            }

            curr.pop_back();
            mp[ch - 'a']++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {

        vector<int> mp(26, 0);

        for (int i = 0; i < s.length(); i++) {
            mp[s[i] - 'a']++;   
        }

        string curr = "";
        bool can_do = false;

        solve(curr, target, mp, 0, can_do); 

        return res;
    }
};