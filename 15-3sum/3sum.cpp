class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            // I already cover this element don't need to cover anymore
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = nums[i];
            while (j < k) {
                int curr_value = nums[j] + nums[k] + nums[i];
                // I have to increse value
                if (curr_value < 0) {
                    j++;
                    // decrese value
                } else if (curr_value > 0) {
                    k--;
                } else {
                    answer.push_back({nums[i], nums[j], nums[k]});
                    while (j + 1 <= k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    while (k - 1 >= j && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    j++;
                    k--;
                }
            }
        }
        return answer;
    }
};