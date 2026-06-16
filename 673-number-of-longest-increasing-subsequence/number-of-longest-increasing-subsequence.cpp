class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // bottom up 
        int n = nums.size();
        if(n==1){
            return 1;
        }
        vector<int> t(nums.size() + 1, 1);
        vector<int>count(nums.size()+1,1);
        int maxi = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if(nums[j]<nums[i]){
                    if(t[j]+1==t[i]){
                        count[i]+=count[j];
                    }
                    else if(t[j]+1>t[i]){
                        t[i]=1+t[j];
                        count[i]=count[j];
                    }
                }
                maxi=max(maxi,t[i]);
             
            }
        
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] == maxi) {
                cnt+=count[i];
            }
        }
        return cnt;
    }
};