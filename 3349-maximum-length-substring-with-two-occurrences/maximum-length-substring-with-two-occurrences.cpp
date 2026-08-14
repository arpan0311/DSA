class Solution {
public:
bool solve(unordered_map<char,int>&hash){
    bool can=false;
    for(auto&it:hash){
        if(it.second<=2){
            continue;
        }
        else if(it.second>2){
            return false;
        }
    }
    return true;
}
    int maximumLengthSubstring(string s) {
        int len=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int>mp;
            for(int j=i;j<s.length();j++){
                mp[s[j]]++;
                if(solve(mp)){
                    len=max(len,j-i+1);
                }
            }
        }
        return len;
    }
};