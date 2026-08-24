class Solution {
public:
    int maxCoins(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-2;
        int cnt=0;
        while(i<j){
            cnt+=nums[j];
            i++;
            j=j-2;
        }
        return cnt;
    }
};