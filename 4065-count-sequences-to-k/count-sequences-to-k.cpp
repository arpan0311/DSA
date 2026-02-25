class Solution {
public:
    int solve(vector<int>& nums, int i, long long num, long long den,
              long long k, unordered_map<string, long long>& hash) {
        if (i == nums.size()) {
            if (den != 0 && num % den == 0) {
                return (num / den == k);
            }
            return 0;
        }

        string key = to_string(i) + "_" + to_string(num) + "_" + to_string(den);
        if (hash.find(key) != hash.end()) {
            return hash[key];
        }

        long long ans = 0;

        // 1️⃣ Put in numerator
        if (nums[i] != 0 && num <= LLONG_MAX / nums[i]) {
            long long new_num = num * nums[i];
            long long new_den = den;

            long long g = __gcd(new_num, new_den);
            new_num /= g;
            new_den /= g;

            ans += solve(nums, i + 1, new_num, new_den, k, hash);
        }

        // 2️⃣ Skip
        ans += solve(nums, i + 1, num, den, k, hash);

        // 3️⃣ Put in denominator
        if (nums[i] != 0 && den <= LLONG_MAX / nums[i]) {
            long long new_num = num;
            long long new_den = den * nums[i];

            long long g = __gcd(new_num, new_den);
            new_num /= g;
            new_den /= g;

            ans += solve(nums, i + 1, new_num, new_den, k, hash);
        }
        return hash[key] = ans;
    }

    int countSequences(vector<int>& nums, long long k) {
        unordered_map<string, long long> hash;
        return solve(nums, 0, 1, 1, k, hash);
    }
};