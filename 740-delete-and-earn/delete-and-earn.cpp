class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> hash;

        // int dp[20005];???
        vector<int> freq(20005);
        for (auto& value : nums) {
            freq[value] = freq[value] + 1;
        }

        int maxi = *max_element(
            nums.begin(),
            nums.end()); // kyoki hame dp ka maxi return karna h isliye

        vector<int> dp(20005);
        
        dp[1]=max(freq[0],freq[1]*1);
        dp[2]=max(dp[1],freq[2]*2);

        for(int i=3;i<=maxi;i++){
            dp[i]=max(dp[i-1],dp[i-2]+i*freq[i]);
        }
        return dp[maxi];
    }
};