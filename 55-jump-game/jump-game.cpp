class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=nums[0];
        if(nums[0]==0&&nums.size()>1){
            return false;
        }
        else if(nums[0]==0&&nums.size()==1){
            return true;
        }
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i>maxi){
                return false;
            }
            maxi=max(maxi,i+nums[i]);
        }
        return true;
    }
};