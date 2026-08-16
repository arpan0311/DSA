class Solution {
public:
    long long solve(long long start, long long next, long long n) {
        long long countNum = 0;

        while (start <= n) {
            countNum += (next - start);

            start *= 10;
            next *= 10;
            next = min(next, n + 1);
        }

        return countNum;
    }

    long long findKthNumber(long long n, long long k) {
        long long s = 1;
        k--;

        while (k > 0) {
            long long num = solve(s, s + 1, n);

            if (num <= k) {
                s++;
                k -= num;
            }
            else {
                s *= 10;
                k--;
            }
        }

        return s;
    }
};