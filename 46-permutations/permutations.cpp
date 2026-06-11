class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&answer,vector<int>temp,vector<bool>&pick){
        if(temp.size()==nums.size()){
            answer.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!pick[i]){
                pick[i]=true;
                temp.push_back(nums[i]);
                solve(nums,answer,temp,pick);
                temp.pop_back();
                pick[i]=false;
            }
        }


    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>answer;
        vector<int>temp;
        vector<bool>pick(nums.size(),false);
        solve(nums,answer,temp,pick);
        return answer;
    }
};