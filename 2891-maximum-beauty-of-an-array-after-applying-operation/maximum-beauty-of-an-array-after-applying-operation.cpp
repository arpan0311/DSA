class Solution {
public:
static bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int,int>>answer;
        for(int i=0;i<nums.size();i++){
            int left=max(0,nums[i]-k),right=nums[i]+k;
            answer.push_back({left,1});
            answer.push_back({right,-1});
        }
        sort(answer.begin(),answer.end(),cmp);

        int maxi=0,curr=0;
        for(int i=0;i<answer.size();i++){
            curr+=answer[i].second;
             maxi=max(maxi,curr);
        }
        return maxi;
    }
};