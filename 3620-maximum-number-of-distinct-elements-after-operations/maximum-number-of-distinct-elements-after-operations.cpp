class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0,mini=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int lb=nums[i]-k;
            int ub=nums[i]+k;
            if(mini<lb){
                mini=lb;
                cnt++;
            }
            else if(mini<ub){
                mini++;
                cnt++;
            }
        }
        return cnt;
    }
};