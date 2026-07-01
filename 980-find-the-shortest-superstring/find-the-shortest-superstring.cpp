class Solution {
public:
    unordered_map<long long, string> dp;

    // overlap[i][j] = common characters between
    // suffix of words[i] and prefix of words[j]
    int getOverlap(string &a, string &b) {
        int ans = 0;
        int m = min(a.size(), b.size());

        for (int len = 1; len <= m; len++) {
            if (a.substr(a.size() - len) == b.substr(0, len))
                ans = len;
        }

        return ans;
    }

    string dfs(int last,
               vector<string> &words,
               int mask,
               vector<vector<int>> &overlap) {

        int n = words.size();

        // Base Case:
        // All words are already used.
        if (mask == (1 << n) - 1)
            return words[last];

        // Memoization key
        long long key = ((long long)mask << 5) | last;

        if (dp.count(key))
            return dp[key];

        string best = "";
        int bestLen = INT_MAX;

        // Try every unused word
        for (int i = 0; i < n; i++) {

            if (mask & (1 << i))
                continue;

            // Solve remaining problem starting from word i
            string curr = dfs(i,
                              words,
                              mask | (1 << i),
                              overlap);

            // Merge current word with returned answer
            string candidate =
                words[last] +
                curr.substr(overlap[last][i]);

            if (candidate.size() < bestLen) {
                bestLen = candidate.size();
                best = candidate;
            }
        }

        return dp[key] = best;
    }

    string shortestSuperstring(vector<string> &words) {

        int n = words.size();

        // overlap matrix
        vector<vector<int>> overlap(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i == j)
                    continue;

                overlap[i][j] =
                    getOverlap(words[i], words[j]);
            }
        }

        string ans = "";
        int bestLen = INT_MAX;

        // Try every word as starting word
        for (int i = 0; i < n; i++) {

            string curr =
                dfs(i,
                    words,
                    1 << i,
                    overlap);

            if (curr.size() < bestLen) {
                bestLen = curr.size();
                ans = curr;
            }
        }

        return ans;
    }
};