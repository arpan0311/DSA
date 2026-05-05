class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                sum+=(nums[i]-nums[i+1]);
            }
        }
        return sum;
    }
};