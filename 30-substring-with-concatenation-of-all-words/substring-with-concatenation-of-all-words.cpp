class Solution {
public:
    bool areEqual(unordered_map<string, int>& mp1,
                  unordered_map<string, int>& mp2) {
        if (mp1.size() != mp2.size()) {
            return false;
        }

        for (auto& it : mp1) {
            if (mp2.find(it.first) == mp2.end() || mp2[it.first] != it.second) {
                return false;
            }
        }

        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> hash;
        for (int i = 0; i < words.size(); i++) {
            hash[words[i]]++;
        }

        vector<int> result;
   
        int k = words[0].size();
        long long n = k * (int)words.size();
        for (int m = 0; m < k; m++) {
            unordered_map<string, int> check;
            int j = m, i = m;
            while (j < s.length()) {
                string p = s.substr(j, k);
                check[p]++;
                if (hash.find(p) == hash.end() && i < j) {
                    i = j + k;
                    j = j + k;
                    check.clear();
                    continue;
                }
                // valid triming
                int len = (j - i) + k;
                if (len == n) {
                    if (areEqual(hash, check)) {
                        result.push_back(i);
                    }
                    string p = s.substr(i, k);

                    if (check[p] == 1) {
                        check.erase(p);
                    } else {
                        check[p]--;
                    }

                    i = i + k;
                }
                j = j + k;
            }
        }

        return result;
    }
};