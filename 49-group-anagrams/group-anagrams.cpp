class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map<string,vector<string>>answer;

        for(int i=0;i<str.size();i++){
            string temp=str[i];
            sort(temp.begin(),temp.end());
            answer[temp].push_back(str[i]);
        }
         vector<vector<string>>res;
         for(auto&it:answer){
            res.push_back(it.second);
         }
         return res;
    };
};
