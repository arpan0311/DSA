class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

    
        vector<int> prefix_sum(n+1);
        prefix_sum[1] = 1;
        int curr_cost;
        for (int i = 1; i < n-1; ++i) {
            if (abs(nums[i] - nums[i+1]) < abs(nums[i] - nums[i-1])) {
                curr_cost = 1;
            } else {
                curr_cost = abs(nums[i] - nums[i+1]);
            }
            prefix_sum[i+1] = prefix_sum[i] + curr_cost;
        }

        vector<int> rev_prefix_sum(n+1);
        rev_prefix_sum[n-1] = 1;
        for (int i = n-2; i > 0; --i) {
            if (abs(nums[i] - nums[i-1]) <= abs(nums[i] - nums[i+1])) {
                curr_cost = 1;
            } else {
                curr_cost = abs(nums[i] - nums[i-1]);
            }
            rev_prefix_sum[i] = rev_prefix_sum[i+1] + curr_cost;
        }

        vector<int> tot_cost;
        for (auto& query : queries) {
            int cost = 0;
            if (query[0] < query[1]) {
                cost = prefix_sum[query[1]] - prefix_sum[query[0]];
            } else {
                // maderchod Point 1 ghanta pigya behanchod...
                cost = rev_prefix_sum[query[1]+1] - rev_prefix_sum[query[0]+1];
            }
            tot_cost.push_back(cost);
        }

        return tot_cost;
    }
};