class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> hash;
        int cnt = 0;
        int n = s.length();
        int i = 0, j = 0;
        while (j < s.length()) {
            hash[s[j]]++;
            while (hash.size() == 3) {
                    cnt+=(n-j);
                if (hash[s[i]] > 1) {
                    hash[s[i]]--;
                } else {
                    hash.erase(s[i]);
                }
                i++;
            }
            j++;
        }

        return cnt;
    }
};