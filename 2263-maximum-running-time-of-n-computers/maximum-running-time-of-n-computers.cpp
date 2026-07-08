class Solution {
public:
    bool solve(long long mid, vector<int>& batteries, int n) {
        long long energy = 0;

        for (int x : batteries)
            energy += min((long long)x, mid);

        return energy >= mid * n;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0;
        long long high = accumulate(batteries.begin(), batteries.end(), 0LL) / n;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (solve(mid, batteries, n))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};