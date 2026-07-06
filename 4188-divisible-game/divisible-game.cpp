class Solution {
public:
    const int mod = 1e9 + 7;

    // find all possible factors
    void solve(int val, set<int>& s) {
        for (int i = 2; i * i <= val; i++) {
            if (val % i == 0) {
                s.insert(i);
                if (i * i != val)
                    s.insert(val / i);
            }
        }
        s.insert(val);
    }

    int divisibleGame(vector<int>& nums) {

        set<int> st;

        for (int x : nums) {
            if (x > 1) {
                solve(x, st);
            }
        }

        vector<int> answer(st.begin(), st.end());

        int save = 2;
        long long ans = -*min_element(nums.begin(), nums.end());

        for (int k : answer) {

            long long curr = 0;
            long long diff = LLONG_MIN;

            for (int x : nums) {

                long long val;

                if (x % k == 0)
                    val = x;
                else
                    val = -1LL * x;

                curr = max(curr + val, val);
                diff = max(diff, curr);
            }

            if (diff > ans) {
                ans = diff;
                save = k;
            } else if (diff == ans && k < save) {
                save = k;
            }
        }
        long long res = (ans%mod+mod)%mod;
        return (1LL * save * res) % mod;
    }
};