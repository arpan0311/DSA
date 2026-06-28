class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int once=0,zero=0;
        int j=0,i=0,res=0;
        while(j<nums.size()){
            if(nums[j]==0){
                zero++;
            }
            else{
                once++;
            }
            if(j-i+1-once>k){
                 if(nums[i]==0){
                zero--;
            }
            else{
                once--;
            }
                i++;
            }
            if(j-i+1-once<=k){
                res=max(res,j-i+1);
            }
            j++;
        }
        return res;
    }
};