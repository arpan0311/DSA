class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 3) {
            return 0;
        }
        

        sort(nums.begin(), nums.end());
        // remove first and last,
        return min(abs(nums[n-2]-nums[1]),min(abs(nums[n-1]-nums[2]),abs(nums[0]-nums[n-3])));
       
    }
};