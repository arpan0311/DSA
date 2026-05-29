class Solution {
public:
    void dfs(int i, unordered_set<int>& st,
             unordered_map<int, vector<int>>& adj) {
        st.insert(i);

        for (auto& it : adj[i]) {
            if (!st.count(it)) {
                dfs(it, st, adj);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) {
                    continue;
                }
                long long dis =
                    1LL * (nums[i][0] - nums[j][0]) * (nums[i][0] - nums[j][0]) +
                    1LL * (nums[i][1] - nums[j][1]) * (nums[i][1] - nums[j][1]);
                if (1LL * nums[i][2] * nums[i][2] >= dis) {
                    adj[i].push_back(j);
                }
            }
        }
        unordered_set<int> st;
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            dfs(i, st, adj);
            res = max(res, (long long)st.size());
            st.clear();
        }

        return res;
    }
};