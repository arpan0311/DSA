class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int time=(nums.size()+1)/2;
        for(int i=0;i<=nums.size()-time;i++){
            if(nums[i]==nums[i+time-1]){
                return nums[i];
            }
        }
        return -1;
    }
};
// i -> i+ 3
// 1 1 1 2 2 2 2 