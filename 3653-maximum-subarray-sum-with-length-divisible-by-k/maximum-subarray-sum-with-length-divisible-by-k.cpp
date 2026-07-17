class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // extantision of kadan's algorithm
        // find prefix sum

        vector<long long> prefix;
        prefix.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            prefix.push_back(prefix[i - 1] + nums[i]);
        }
        long long maxi = LLONG_MIN;
        int i = 0, j = 0;

        for (int start = 0; start < k; start++) {
            long long curr = 0;
            int i = start;

            while (i + k - 1 < nums.size()) {
                int j = i + k - 1;

                long long curr_sum = prefix[j] - (i ? prefix[i - 1] : 0);

                curr = max(curr_sum, curr + curr_sum);
                maxi = max(maxi, curr);

                i += k;
            }
        }
        return maxi;
    }
};