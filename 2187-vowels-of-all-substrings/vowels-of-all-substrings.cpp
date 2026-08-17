class Solution {
public:
    int solve(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return 1;
        }
        return 0;
    }
    long long countVowels(string word) {
        long long cnt = 0;
        int n=word.size();
        for (int i = 0; i < word.size(); i++) {
            if (solve(word[i])) {
                cnt += (long long)(n - i) * (i + 1);
            }
        }
        return cnt;
    }
};