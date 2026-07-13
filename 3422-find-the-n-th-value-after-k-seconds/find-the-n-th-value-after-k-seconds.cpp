class Solution {
public:
const int mod=1e9+7;
    int valueAfterKSeconds(int n, int k) {
        vector<long long>ans(n,1);
        while(k--){
            for(int i=1;i<n;i++){
                ans[i]=(ans[i]+ans[i-1])%mod;
            }
        }
        return ans[n-1]%mod;
    }
};