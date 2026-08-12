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
    vector<int> solve1(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
            }
        }
        return lis;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> lis = solve(nums);
        vector<int> lds = solve1(nums);

        int answer = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (lis[i] > 1 && lds[i] > 1) {
                answer = max(answer, lis[i] + lds[i] - 1);
            }
        }
        return nums.size() - answer;
    }
};