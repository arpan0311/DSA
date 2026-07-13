class Solution {
public:
    long long dp[20][2];

    long long solve(int idx, int limit,
                    string &s, string &e, bool tight) {

        int n = e.size();
        int k = s.size();

        if (idx == n - k) {
            if (!tight)
                return 1;

            string boundSuffix = e.substr(idx);

            return s <= boundSuffix;
        }

        if (dp[idx][tight] != -1)
            return dp[idx][tight];

        long long total = 0;

        int ub = limit;

        if (tight) {
            ub = min(limit, e[idx] - '0');
        }

        for (int i = 0; i <= ub; i++) {

            bool newTight =
                tight && (i == e[idx] - '0');

            total += solve(idx + 1,
                           limit,
                           s,
                           e,
                           newTight);
        }

        return dp[idx][tight] = total;
    }

    long long count(long long num, int limit, string &s) {

        if (num < 0)
            return 0;

        string e = to_string(num);

        if (e.size() < s.size())
            return 0;

        for (char ch : s) {
            if (ch - '0' > limit)
                return 0;
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, limit, s, e, true);
    }

    long long numberOfPowerfulInt(long long start,
                                  long long finish,
                                  int limit,
                                  string s) {

        return count(finish, limit, s)
             - count(start - 1, limit, s);
    }
};