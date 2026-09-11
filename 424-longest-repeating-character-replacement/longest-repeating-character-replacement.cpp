class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int>hash;
        int max_frec=0;
        int i=0,j=0;
        int answer=0;
        while(j<s.length()){
            hash[s[j]]++;
            max_frec=max(max_frec,hash[s[j]]);
            while(j-i+1-max_frec>k){
                hash[s[i]]--;
                i++;
            }
            answer=max(answer,j-i+1);
            j++;
        }
        return answer;
    }
};