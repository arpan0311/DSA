class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        long long sum=0;
        int len=INT_MAX;
        int i=0,j=0;
        while(j<nums.size()){
                sum+=nums[j];
                while(sum>=k){
                    len=min(len,j-i+1);
                    sum-=nums[i];
                    i++;
                }
                if(sum>=k){
                    len=min(len,j-i+1);
                }
                j++;
        }
        return len==INT_MAX?0:len;
    }
};