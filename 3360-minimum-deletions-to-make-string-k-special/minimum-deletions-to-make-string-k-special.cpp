class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<long long> ch(26, 0);
        for (int i = 0; i < word.size(); i++) {
            ch[word[i] - 'a']++;
        }
        int ans = INT_MAX;

        for (int i = 0; i < ch.size(); i++) {
            int cnt = 0;

            for (int j = 0; j < ch.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (ch[j] < ch[i]) {
                    cnt += ch[j];
                } else {
                    int curr = abs(ch[i] - ch[j]);
                    if (curr > k) {
                        cnt += (curr - k);
                    }
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};