class Solution {
public:
    int maxArea(vector<int>& nums) {
        int max_water=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            int curr_water=(j-i)*min(nums[i],nums[j]);
            max_water=max(max_water,curr_water);
            if(nums[i]<=nums[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return max_water;
    }
};