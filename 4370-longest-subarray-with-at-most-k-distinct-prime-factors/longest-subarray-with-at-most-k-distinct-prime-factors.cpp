class Solution {
public:
    void solve1(int val, unordered_map<int, int>& hash) {
        for (int i = 2; i * i <= val; i++) {
            if (val % i == 0) {
                // ek hi bar contribute karenge
                while (val % i == 0) {
                    val = val / i;
                }
                if (hash[i] == 1) {
                    hash.erase(i);
                } else {
                    hash[i]--;
                }
            }
        }
        if (val > 1) {
            if (hash[val] == 1)
                hash.erase(val);
            else
                hash[val]--;
        }
    }

    void solve(int val, unordered_map<int, int>& hash) {
        for (int i = 2; i * i <= val; i++) {
            if (val % i == 0) {
                // ek hi bar contribute karenge
                while (val % i == 0) {
                    val = val / i;
                }
                hash[i]++;
            }
        }
        if (val > 1) {
            hash[val]++;
        }
    }

    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> hash;

        int i = 0, j = 0, n = nums.size();
        int cnt = 0;
        while (j < n) {
            // add elements...
            solve(nums[j], hash);
            // shrink
            while (hash.size() > k && i < j) {
                cout << nums[i] << " ";
                solve1(nums[i], hash);
                i++;
            }

            if (hash.size() <= k) {
                cnt = max(cnt, j - i + 1);
            }
            j++;
        }
        return cnt;
    }
};