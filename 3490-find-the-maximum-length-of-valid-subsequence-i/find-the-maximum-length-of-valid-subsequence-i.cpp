class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd=0,even=0,oddeven=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                odd++;
            }
            else{
                even++;
            }
        }
        int first=nums[0]%2;
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2!=first){
                first=nums[i]%2;
                oddeven++;
            }
        }
        return max({odd,even,oddeven});
    }
};