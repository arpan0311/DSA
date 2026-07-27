class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // only we have positive integers
        if(nums[0]>1){
            return 1;
        }
        int  k=0;
        // 0  1 2 
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=k){
                continue;
            }
            else if(nums[i]==k+1){
                k++;
            }
            else{
                return k+1;
            }
        }
        return k+1;
    }   
};