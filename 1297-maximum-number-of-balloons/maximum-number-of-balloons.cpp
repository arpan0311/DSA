class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>hash;
        string s="balloon";
        // string 
        for(auto&it:s){
            hash[it]++;
        }

        unordered_map<char,int>hash2;
        for(auto&it:text){
            hash2[it]++;
        }
        int mini=INT_MAX;
        bool iscan=false;
        for(auto&it:hash){
            if(hash2.find(it.first)==hash2.end()){
                return 0;
            }
            else{
                mini=min(mini,hash2[it.first]/it.second);
            }
        }

        return mini;
    }
};