class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int answer=INT_MAX;
        int sum=0;
        // len minimum karni 
        int i=0,j=0;
        while(j<nums.size()){
            sum+=nums[j];
           
            while ((i <= j && sum >= k) || (i <= j && nums[i] <= 0)){
                if(sum>=k&&j-i+1>0){
                    answer=min(answer,j-i+1);
                }
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return (answer==INT_MAX)?0:answer;
    }
};