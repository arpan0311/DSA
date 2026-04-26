class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
       if(nums.size()==1){
        return {nums[0]};
       }
        vector<int>suffix(nums.size(),nums[n-1]);
        for(int i=nums.size()-2;i>=0;i--){
           suffix[i]=max(nums[i],suffix[i+1]);
        }
        int maxi=nums[0];
        vector<int>ans;
         ans.push_back(nums[0]);//0th element
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                ans.push_back(nums[i]);
            }
            else if(nums[i]>suffix[i+1]){
                ans.push_back(nums[i]);
            }
        }
            ans.push_back(nums[n-1]);
            return ans;
    }
};