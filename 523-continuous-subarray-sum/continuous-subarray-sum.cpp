class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // reminder store karo...
        unordered_map<int, int> hash;
        // int len = 0;
        int sum = 0;
        hash[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (hash.find(sum % k) != hash.end()) {
                if (i - hash[sum % k] >= 2) {
                    return true;
                }
            } else {
                hash[sum % k] = i;
            }
        }
        return false;
    }
};