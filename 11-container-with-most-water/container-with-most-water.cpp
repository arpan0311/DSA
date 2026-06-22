class Solution {
public:
    int maxArea(vector<int>& nums) {
        int max_water=0;
        int i=0,j=nums.size()-1;
        while(i<j){
        int max_height=min(nums[i],nums[j]);
        int area=(j-i)*max_height;
        max_water=max(max_water,area);
            if(nums[i]>nums[j]){
                // keep i;
                j--;
            }
            else{
                // keep j
                i++;
            }
        }
        return max_water;
    }
};