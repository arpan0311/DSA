class Solution {
public:
    void solve(vector<int>& nums, int k, vector<int> temp,
               set<vector<int>>& answer) {
        if (k == nums.size()) {
            answer.insert(temp);
            return;
        }

        for (int i = k; i < nums.size(); i++) {
            solve(nums, i + 1, temp, answer);
            temp.push_back(nums[i]);
            solve(nums, i + 1, temp, answer);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> answer;
        vector<int> temp;
        solve(nums, 0, temp, answer);
        vector<vector<int>> res(answer.begin(), answer.end());
        return res;
    }
};