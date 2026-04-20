class Solution {
public:
    const int mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        for (auto& it : queries) {
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];
            for (int i = l; i <= r; i = i + k) {
                nums[i] = (1LL * nums[i] * v) % mod;
            }
        }

        int xor1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            xor1 ^= nums[i];
        }
        return xor1;
    }
};