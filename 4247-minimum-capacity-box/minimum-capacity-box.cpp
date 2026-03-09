class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    int minimumIndex(vector<int>& nums, int itemSize) {
        vector<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=itemSize){
                ans.push_back({nums[i],i});
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0;i<ans.size();i++){
            return ans[0].second;
        }
        return -1;
    }
};