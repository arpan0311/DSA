class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for(int i=n-1;i>=0;i--) {
            unordered_map<int,int> freq;
            int trim = 0;
            for(int j=i;j<n;j++) {
                freq[nums[j]]++;

                if(freq[nums[j]]==2)
                    trim += 2;
                else if(freq[nums[j]]>2)
                    trim++;

                dp[i] = min(dp[i],
                            k + trim + dp[j+1]);
            }
        }

        return dp[0];
    }
};