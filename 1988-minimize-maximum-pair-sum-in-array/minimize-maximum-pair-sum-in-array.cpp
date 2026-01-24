class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size()/2;i++){
            sum=nums[i]+nums[nums.size()-1-i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};