class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = nums.size() - 1;
                while (k < l) {
                    long long curr_sum =
                        (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (curr_sum < target) {
                        k++;
                    } else if (curr_sum > target) {
                        l--;
                    } else {
                        answer.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k + 1 < l && nums[k] == nums[k + 1]) {
                            k++;
                        }
                        while (l - 1 > k && nums[l] == nums[l - 1]) {
                            l--;
                        }
                        k++;
                        l--;
                    }
                }
            }
        }
        return answer;
    }
};