class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int left_sum = 0;
        int left_alice = 0, left_bob = 0;

        int right_sum = 0;
        int right_bob = 0, right_alice = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] != '?') {
                left_sum += num[i] - '0';
            }
            else {
                left_bob++;
            }
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] != '?') {
                right_sum += num[i] - '0';
            }
            else {
                right_bob++;
            }
        }

        return (2 * left_sum + 9 * left_bob !=
                2 * right_sum + 9 * right_bob);
    }
};