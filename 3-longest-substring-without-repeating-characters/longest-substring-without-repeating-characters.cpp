class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int i = 0, j = 0;
        int maxi = 0;
        while (j < s.length()) {
            hash[s[j]]++;
            while (hash[s[j]] >= 2 && i < j) {
                if (hash[s[i]] == 1) {
                    hash.erase(s[i]);
                } else {
                    hash[s[i]]--;
                }
                i++;
            }
            
            maxi = max(maxi, j-i+1);
            cout<<maxi<<" ";
            j++;
        }
        return maxi;
    }
};