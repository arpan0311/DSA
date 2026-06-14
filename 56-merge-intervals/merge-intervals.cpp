class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>>answer;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int start=nums[i][0];
            int end=nums[i][1];
         
            int j=i+1;
            while(j<nums.size()&&end>=nums[j][0]){
                end=max(end,nums[j][1]);
                j++;
            }
            i=j-1;
            vector<int>temp;
            temp.push_back(start),temp.push_back(end);
            answer.push_back(temp);
        }
        return answer;
    }
};