class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long prev = 0;
        long long total_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            total_sum += nums[i];
        }
        int n = nums.size();
        vector<long long> suffix(n + 1, -1);
        suffix[n] = 1;
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if(nums[i]>total_sum/suffix[i+1]){
                break;
            }
            long long value=(long long)(nums[i] * suffix[i + 1]);
            if (value <= total_sum) {
                suffix[i] = value;
            } else {
                break;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (prev == suffix[i + 1]) {
                return i;
            }
            prev+=nums[i];
        }
        return -1;
    }
};