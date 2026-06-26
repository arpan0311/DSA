class Solution {
public:
  bool isTrue(vector<int>& ans) {
        for(int i=0; i<26; i++){
            if(ans[i] != 0){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s) {
         vector<int> ans(26, 0);   // frequency of p
        for(char ch : s1){
            ans[ch - 'a']++;
        }
        int i = 0, j = 0;

        while(j < s.length()){
            ans[s[j] - 'a']--;   // take current char into window

            if(j - i + 1 == s1.length()){  // window size reached
                if(isTrue(ans)){
                   return true;
                }
                ans[s[i] - 'a']++;  // remove left char
                i++;
            }
            j++;
        }

        return false;
    }
};