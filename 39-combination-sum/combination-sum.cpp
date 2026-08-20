class Solution {
public:
    void solve(vector<int>& nums, vector<int> temp, int k, int target, int curr,
               vector<vector<int>>& answer) {

        if (curr == target) {
            answer.push_back(temp);
            return;
        }
        if (curr > target) {
            return;
        }
        if(k>=nums.size()){
            return;
        }
       

        if (curr + nums[k] <= target) {
            temp.push_back(nums[k]);
            solve(nums, temp, k, target, curr + nums[k], answer);
            temp.pop_back();
            solve(nums,temp,k+1,target,curr,answer);
        }
       
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> temp;
        int curr = 0;
        solve(nums, temp, 0, target, curr, answer);
        return answer;
    }
};