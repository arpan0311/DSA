class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // using binary search 
        int res=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int find=nums[i]+2*k;
            int low=i+1,high=n-1;
            int ans=i;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(nums[mid]>find){
                    high=mid-1;
                }
                else if(nums[mid]<find){
                    // save and move;
                    ans=mid;
                    low=mid+1;
                }
                else{
                    // save and move
                    ans=mid;
                    low=mid+1;
                }
            }
            res=max(res,ans-i+1);
        }
        return res;
    }
};