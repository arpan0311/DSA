class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) { 

        sort(nums.begin(),nums.end());

        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int end=nums[i][1];
            int j=i+1;
            while(j<nums.size()&&nums[j][0]<=end){
                end=min(nums[j][1],end);
                j++;
            }
            i=j-1;
            cnt++;
        }
        return cnt;
        
    }
};