class Solution {
public:
    bool areEqual(unordered_map<int, int>& mp1, unordered_map<int, int>& mp2) {
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
    vector<int> findAnagrams(string nums, string p) {

        if (nums.length() < p.length()) {
            return {};
        }

        unordered_map<int, int> temp;
        // save elements of
        for (int i = 0; i < p.length(); i++) {
            temp[p[i]]++;
        }

        int i = 0, j = 0;
        vector<int> result;
        unordered_map<int, int> hash;
        while (j < nums.size()) {
            hash[nums[j]]++;

            // filter...
            while (i <= j && temp.find(nums[i]) == temp.end()) {
               if (hash[nums[i]] == 1) {
                    hash.erase(nums[i]);
                } else {
                    hash[nums[i]]--;
                }
                i++;
            }
            // valid triming
            if (j - i + 1 == p.length()) {
                if (areEqual(hash, temp)) {
                    result.push_back(i);
                }
                if (hash[nums[i]] == 1) {
                    hash.erase(nums[i]);
                } else {
                    hash[nums[i]]--;
                }

                i++;
            }
            j++;
        }
        return result;
    }
};