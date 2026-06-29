class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long max_sum=nums[0];
        long long curr=0;
        int i=0,j=0;
        while(j<nums.size()){
            curr+=nums[j];
            max_sum=max(max_sum,curr);
            // to carry - value does not make sense 
            if(curr<0){
                curr=0;
            }  
            j++;
        }
        return max_sum;
    }
};