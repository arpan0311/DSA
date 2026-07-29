class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
         int total=0;
        for(auto&it:nums){
            total+=it;
        }
        int mini=total;
        int curr=0;
        for(int i=0;i<nums.size();i++){
           int curr_sum=min(nums[i],curr+nums[i]);
           curr=curr_sum;
           mini=min(mini,curr_sum);
        }
        int maximum_sum=INT_MIN;
        curr=0;
        for(int i=0;i<nums.size();i++){
           int curr_sum=max(nums[i],curr+nums[i]);
           curr=curr_sum;
           maximum_sum=max(maximum_sum,curr_sum);
        }
        cout<<mini<<endl;
        cout<<maximum_sum<<endl;
        if(total==mini){
            return maximum_sum;
        }
        return max(maximum_sum,total-mini);
    }
};