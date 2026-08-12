class Solution {
public:
vector<int> solve(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
            }
        }
        return lis;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>answer=solve(nums);
        return *max_element(answer.begin(),answer.end());
    }
};