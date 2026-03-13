class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // I have too done it one more time to get it properly.
        int n= nums.size();
        vector<int>lis(n,1),preInd(n,-1);
        int maxLen=1,idx=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&& lis[i]<lis[j]+1){
                    lis[i]=1+lis[j];
                    preInd[i]=j;
                }

                if(lis[i]>maxLen){
                    maxLen=lis[i];
                    idx=i;
                }
            }
        }
        vector<int>ans;
        while(idx!=-1){
            ans.push_back(nums[idx]);
            idx=preInd[idx];
        }
        return ans;
    }
};