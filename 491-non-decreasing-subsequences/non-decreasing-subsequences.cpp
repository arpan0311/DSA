class Solution {
public:
    void arpan(vector<vector<int>> &answer, vector<int>& nums, int idx,
               vector<int>& curr) {

        if (curr.size() >= 2) {
            answer.push_back(curr);
        }

        unordered_set<int> used;

        for (int i = idx; i < nums.size(); i++) {

            if (used.count(nums[i])) continue;

            if (!curr.empty() && nums[i] < curr.back()) continue;

            used.insert(nums[i]);

            curr.push_back(nums[i]);
            arpan(answer, nums, i + 1, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> curr;
        arpan(answer, nums, 0, curr);
        return answer;
    }
};