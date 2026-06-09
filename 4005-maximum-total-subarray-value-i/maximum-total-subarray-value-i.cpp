class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        // find a subarray that has maximum diff 
        if(nums.size()==0||nums.size()==1){
            return 0;
        }
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        long long  ans=maxi-mini;
    ans=ans*k;
    return ans;
    }
};