class Solution {
public:
    void solve(string s, int k, int n, set<string>& answer, int sum) {

        if (sum > k) return;

        if (s.length() == n) {
            answer.insert(s);
            return;
        }

        int i = s.length();   

        if (!s.empty()) {
            if (s.back() == '0') {
                solve(s + '0', k, n, answer, sum);

                if (sum + i <= k) {
                    solve(s + '1', k, n, answer, sum + i);
                }
            } else {
                solve(s + '0', k, n, answer, sum);
            }
        } else {
            solve(s + '0', k, n, answer, sum);

            if (sum + i <= k) {
                solve(s + '1', k, n, answer, sum + i);
            }
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        set<string> answer;

        solve("", k, n, answer, 0);

        return vector<string>(answer.begin(), answer.end());
    }
};