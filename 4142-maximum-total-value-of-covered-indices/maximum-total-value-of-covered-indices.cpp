class Solution {
public:
long long dp[100001][2];
    long long solve(string &s, vector<int>& nums, bool can_perform, int i) {
        if (i < 0) {
            return 0;
        }
        if(dp[i][can_perform]!=-1){
            return dp[i][can_perform];
        }
        long long  take = 0;
        long long not_take = 0;

    //   piche se aaya true forword hua one 
        if (can_perform) {

            if (s[i] == '0') {
                take = nums[i]+ solve(s, nums, false, i - 1);
            }
            else {
          
                take =  nums[i]+ solve(s, nums, false, i - 1);

               
                not_take =   nums[i] + solve(s, nums, true, i - 1);
            }
        }
        else {

            if (s[i] == '0') {
                take = solve(s, nums, false, i - 1);
            }
            else {
               
                take = nums[i] + solve(s, nums, false, i - 1);

             
                not_take = solve(s, nums, true, i - 1);
            }
        }

        return dp[i][can_perform]=max(take, not_take);
    }

    long long maxTotal(vector<int>& nums, string s) {
        bool can_perform = false;
        memset(dp,-1,sizeof(dp));
        return solve(s, nums, can_perform, nums.size() - 1);
    }
};