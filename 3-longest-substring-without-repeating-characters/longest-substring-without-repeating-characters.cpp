class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<int,int>hash;
       int i=0,j=0;
       int answer=0;
       while(j<s.length()){
        hash[s[j]]++;
        while(hash[s[j]]>1){
            hash[s[i]]--;
            i++;
        }
        answer=max(answer,j-i+1);
        j++;
       } 
       return answer;
    }
};