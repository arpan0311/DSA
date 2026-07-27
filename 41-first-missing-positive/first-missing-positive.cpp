class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // this is optimal appraoch for this question 
        bool check=false;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                check=true;
            }
            else if(nums[i]<1||nums[i]>n){
                nums[i]=1;
            }
        }
        if(!check){
            return 1;
        }

        for(int i=0;i<nums.size();i++){
            int  val=abs(nums[i]);
            int  idx=val-1;
            // already mark 
            if(nums[idx]<0){
                continue;
            }
            nums[idx]=-nums[idx];
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};