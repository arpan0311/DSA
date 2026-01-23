class Solution {
public:
    
    long long arpan(vector<int>& nums, int i, int target, int sum,map<string,int>&hash) {
        if (i == nums.size()) {
            if (sum == target) {
                return 1;
            }
            return 0;
        }
        // if(dp[i][sum])/
        if (i > nums.size()) {
            return 0;
        }
       string key = to_string(i) + "_" + to_string(sum);
        if(hash.count(key)){
            return hash[key];
        }
        long long plus = arpan(nums, i + 1, target, sum + nums[i],hash);
        long long minus = arpan(nums, i + 1, target, sum - nums[i],hash);
      
        hash[key]= plus + minus;
        return hash[key];
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int i = 0;
        int sum = 0;
        map<string,int>hash;
        return arpan(nums, i, target, sum,hash);
    }
};