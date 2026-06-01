class Solution {
public:
int dp[51];
    int solve(string s,unordered_map<string,int>&hash,int i){
        if(i==s.length()){
            return 0;
        }
        // minimum extra character
        if(dp[i]!=-1){
            return dp[i];
        }
        int result=1+solve(s,hash,i+1);
        for(int j=i;j<s.length();j++){
            string s1=s.substr(i,j-i+1);
            if(hash.find(s1)!=hash.end()){
                result=min(result,solve(s,hash,j+1));
            }
        }
        return dp[i]=result;
    }
    int minExtraChar(string s, vector<string>&nums) {
        unordered_map<string,int>hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        int i=0;
        memset(dp,-1,sizeof(dp));
        return solve(s,hash,i);
    }
};