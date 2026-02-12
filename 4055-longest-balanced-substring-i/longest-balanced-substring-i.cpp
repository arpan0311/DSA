class Solution {
public:
    bool solve(unordered_map<char,int>&hash){
        int maxi=0;
        for(auto&it:hash){
            maxi=max(maxi,it.second);
        }
     
          for(auto&it:hash){
            if(maxi!=it.second){
                return false;
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int>check;
            for(int j=i;j<s.length();j++){
                check[s[j]]++;
                if(solve(check)==true){
                    cout<<j - i + 1<<" ";
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};