class Solution {
public:
const int mod=1e9+7;
    int valueAfterKSeconds(int n, int k) {
        vector<int>curr(k+1,1),prev(k+1,1);
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                curr[j]=(prev[j]+curr[j-1])%mod;
            }
            prev=curr;
        }
        return curr[k];
    }
};