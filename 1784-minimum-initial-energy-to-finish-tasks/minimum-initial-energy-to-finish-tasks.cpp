class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b) {
        int diffA = a[1] - a[0];
        int diffB = b[1] - b[0];

        if (diffA == diffB) {
            return a[1] > b[1];
        }

        return diffA > diffB;
    }

    bool solve(vector<vector<int>>& tasks, int mid) {
        for (int i = 0; i < tasks.size(); i++) {
            if (mid < tasks[i][1]) {
                return false;
            }

            mid -= tasks[i][0];
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int mini = 0;
        int sum = 0;

        for (auto& it : tasks) {
            mini = max(mini, it[1]);
            sum += it[0];
        }

        int high = sum + mini;
        int low = mini;

        sort(tasks.begin(), tasks.end(), cmp);

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (solve(tasks, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};