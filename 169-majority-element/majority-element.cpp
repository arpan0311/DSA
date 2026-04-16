class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        sort(nums.begin(),nums.end());
        int maxi=(nums.size()+1)/2;
        int cnt=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                cnt++;
            }
            else{
                if(cnt>=maxi){
                    return nums[i];
                }
                cnt=1;
            }
             if(cnt>=maxi){
                    return nums[i];
                }
        }
        return -1;
    }
};