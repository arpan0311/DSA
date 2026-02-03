class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>answer(pref.size(),pref[0]);
        for(int i=pref.size()-1;i>0;i--){
            answer[i]=pref[i-1]^pref[i];
        }
        return answer;
    }
};