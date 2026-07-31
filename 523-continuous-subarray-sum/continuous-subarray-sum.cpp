class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = -1;
        long long sum = 0;
        int i = 0;
        while (i < nums.size()) {
            sum += nums[i];
            int mod = sum % k;
            if (hash.find(mod) != hash.end()) {
                if (i - hash[mod] > 1) {
                    return true;
                }
            } else {
                hash[mod] = i;
            }

            sum = mod;
            i++;
        }
        return false;
    }
};