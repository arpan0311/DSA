class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
         vector<long long>ans;
        int j=0;
        while(j<nums.size()){
            long long curr=nums[j];
            while(!ans.empty()&&ans.back()==curr){
                curr=2*ans.back();
                ans.pop_back();
            }
            ans.push_back(curr);
            j++;
        }
        return ans;
    }
};