class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        long long curr=nums[0];
        int n=nums.size();
        for(int i=1;i<n-1;i++){
            sum-=nums[i-1];
            curr+=nums[i];
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]){
                if(sum<curr){
                    return 0;
                }
                else if(sum>curr){
                    return 1;
                }
                else if(sum==curr){
                    return -1;
                }
            }
        }
        return 12;
    }
};