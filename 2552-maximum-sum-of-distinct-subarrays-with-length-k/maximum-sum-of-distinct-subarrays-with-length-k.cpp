class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        set<int> st;
        int i = 0, j = 0;
        long long sum = 0, max_sum = 0;
        while (j < nums.size()) {
            // start m hi filter laga diya 
            while (st.count(nums[j])) {
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            st.insert(nums[j]);
            sum+=nums[j];
            while (j - i + 1 > k) {
               st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            // window of k
            if (j - i + 1 == k && st.size() == k) {
                max_sum = max(max_sum,sum);
            }
            j++;
        }
        return max_sum;
    }
};