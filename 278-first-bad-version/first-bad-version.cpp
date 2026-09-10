// The API isBadVersion is defined for you.

class Solution {
public:
    int firstBadVersion(int n) {
        long long answer = INT_MAX;

        int low = 0, high = n;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                answer = min(answer, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};