class Solution {
public:

    int dp[1001][1001];

    bool lis2(string &s, string &s1){
        if(s.size() + 1 != s1.size()) return false;

        int i = 0, j = 0;

        while(i < s.size() && j < s1.size()){
            if(s[i] == s1[j]) i++;
            j++;
        }

        return i == s.size();
    }

    int lis(vector<string>& words, int i, int prev){

        if(i >= words.size()) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int take = 0;

        if(prev == -1 || lis2(words[prev], words[i])){
            take = 1 + lis(words, i + 1, i);
        }

        int nottake = lis(words, i + 1, prev);

        return dp[i][prev+1] = max(take, nottake);
    }

    static bool cmp(string &a, string &b){
        return a.size() < b.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        memset(dp, -1, sizeof(dp));
        return lis(words, 0, -1);
    }
};