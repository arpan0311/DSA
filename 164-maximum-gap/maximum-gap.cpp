class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        int i=0;
        while(i<nums.size()){
            if(i+1<nums.size()){
                maxi=max(maxi,nums[i+1]-nums[i]);
            }
            i++;
        }
        return maxi;
    }
};