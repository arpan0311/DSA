class Solution {
public:
    void arpan(set<vector<int>> &answer, vector<int>& nums, int idx,
               vector<int> curr) {
        if (idx >= nums.size()) {
            if (curr.size() >= 2) {
                answer.insert(curr);
            }
            return;
        }
        if (curr.size() >= 2) {
            answer.insert(curr);
        }

        // no sir
        unordered_set<int> st;
        for (int i = idx; i < nums.size(); i++) {
            // valid hai can pick this element
            if (!curr.empty() && curr.back() <= nums[i]) {
                st.insert(nums[i]);
                curr.push_back(nums[i]);
                arpan(answer, nums, i + 1, curr);
                curr.pop_back();
            } else if (curr.empty()) {
                st.insert(nums[i]);
                curr.push_back(nums[i]);
                arpan(answer, nums, i + 1, curr);
                curr.pop_back();
            }
        }
        return;
    }
    


vector<vector<int>>
findSubsequences(vector<int>& nums) {
    set<vector<int>> answer;
    vector<int> curr;
    int i = 0;
    arpan(answer, nums, i, curr);
    return vector<vector<int>>(answer.begin(), answer.end());
}
}
;