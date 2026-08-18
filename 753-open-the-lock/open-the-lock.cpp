class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> s;

        for (auto& it : deadends) {
            s.insert(it);
        }

        string ans = "0000";

        if (s.count(ans)) {
            return -1;
        }

        /// MISTAKE 1:
        /// int steps = 0;
        /// You don't need this because you already store the
        /// number of steps inside the queue as curr_step.

        queue<pair<string, int>> q;
        unordered_set<string> vis;

        q.push({ans, 0});
        vis.insert(ans);

        while (!q.empty()) {

            int n = q.size();

            /// MISTAKE 2:
            /// You were checking target here:
            ///
            /// if (q.front().first == target) {
            ///     return steps;
            /// }
            ///
            /// Better to check after taking the current state
            /// from the queue and use curr_step.

            for (int level = 0; level < n; level++) {

                string curr = q.front().first;
                int curr_step = q.front().second;

                q.pop();

                /// FIX:
                /// Check target for the current state.
                if (curr == target) {
                    return curr_step;
                }

                /// We have 4 wheels.
                for (int i = 0; i < curr.length(); i++) {

                    char ch = curr[i];

                    /// CASE 1:
                    /// Current digit is 0.
                    ///
                    /// 0 can become:
                    /// 0 -> 1
                    /// 0 -> 9

                    if (ch == '0') {

                        curr[i] = '1';

                        if (!vis.count(curr) && !s.count(curr)) {
                            vis.insert(curr);
                            q.push({curr, curr_step + 1});
                        }

                        curr[i] = '9';

                        if (!vis.count(curr) && !s.count(curr)) {
                            vis.insert(curr);
                            q.push({curr, curr_step + 1});
                        }
                    }

                    /// CASE 2:
                    /// Current digit is between 1 and 8.
                    ///
                    /// Example:
                    /// 5 -> 6
                    /// 5 -> 4

                    else if (ch >= '1' && ch <= '8') {

                        curr[i] = ch + 1;

                        if (!vis.count(curr) && !s.count(curr)) {
                            vis.insert(curr);
                            q.push({curr, curr_step + 1});
                        }

                        curr[i] = ch - 1;

                        if (!vis.count(curr) && !s.count(curr)) {
                            vis.insert(curr);
                            q.push({curr, curr_step + 1});
                        }
                    }

                    /// CASE 3:
                    /// Current digit is 9.
                    ///
                    /// 9 can become:
                    /// 9 -> 8
                    /// 9 -> 0

                    else if (ch == '9') {

                        curr[i] = '8';

                        if (!vis.count(curr) && !s.count(curr)) {
                            vis.insert(curr);
                            q.push({curr, curr_step + 1});
                        }

                        curr[i] = '0';

                        if (!vis.count(curr) && !s.count(curr)) {
                            vis.insert(curr);
                            q.push({curr, curr_step + 1});
                        }
                    }

                    /// IMPORTANT:
                    /// Restore the original digit.
                    ///
                    /// Example:
                    /// curr[i] was 5
                    /// We changed it to 6 and then 4.
                    /// Now restore it back to 5.

                    curr[i] = ch;
                }
            }

            /// MISTAKE 3:
            /// steps++;
            ///
            /// Remove it.
            /// curr_step already contains the correct number of steps.
        }

        return -1;
    }
};