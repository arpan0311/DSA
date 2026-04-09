class Solution {
public:
    long long dp[100001];

    long long lower_bound(vector<long long>& arr, int s, long long target){
        int low = s, high = arr.size() - 1;
        int ans = arr.size();

        while(low <= high){
            int mid = (low + high) / 2;

            if(arr[mid] >= target){   
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    long long solve(vector<long long>& nums, unordered_map<long long,long long>& hash, int i){
        if(i >= nums.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        long long ind = lower_bound(nums, i+1, nums[i] + 3);

        
        long long not_take = solve(nums, hash, i + 1);  // just 

        long long take = nums[i] * hash[nums[i]] + solve(nums, hash, ind);

        return dp[i] = max(take, not_take);
    }

    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long,long long> hash;

        for(int i = 0; i < power.size(); i++){
            hash[power[i]]++;
        }

        vector<long long> nums;

        for(auto &it : hash){
            nums.push_back(it.first);
        }

        sort(nums.begin(), nums.end());

        memset(dp, -1, sizeof(dp));

        return solve(nums, hash, 0);
    }
};