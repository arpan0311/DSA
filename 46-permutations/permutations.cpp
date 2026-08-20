class Solution {
public:
    void solve(vector<int>& nums, vector<int>& temp,
               vector<vector<int>>& answer, int mask) {
        if (temp.size() == nums.size()) {
            answer.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (!(mask & (1 << i))) {
                temp.push_back(nums[i]);

                solve(nums, temp, answer, mask | (1 << i));

                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int bits = 0;
        vector<vector<int>> answer;

        int n = nums.size();
        vector<int> temp;
        solve(nums, temp, answer, bits);
        return answer;
    }
};