class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int>prefix(nums.size(),1);
        vector<int>suffix(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                prefix[i]=1+prefix[i-1];
            }
            else{
                continue;
            }
            
        }  
            cout<<endl;

         for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                suffix[i]=1+suffix[i+1];
            }
            else{
                continue;
            }
        
        }
     
        int maxi=0,mini=0;
        for(int i=0;i<nums.size()-1;i++){
            int mini=min(prefix[i],suffix[i+1]);
            maxi=max(maxi,mini);
        }
        return maxi;
    }
};