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

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans(26, 0);   // frequency of p
        for(char ch : p){
            ans[ch - 'a']++;
        }

        vector<int> result;
        int i = 0, j = 0;

        while(j < s.length()){
            ans[s[j] - 'a']--;   // take current char into window

            if(j - i + 1 == p.length()){  // window size reached
                if(isTrue(ans)){
                    result.push_back(i);
                }
                ans[s[i] - 'a']++;  // remove left char
                i++;
            }
            j++;
        }

        return result;
    }
};
