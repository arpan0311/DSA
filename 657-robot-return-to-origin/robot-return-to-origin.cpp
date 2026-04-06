class Solution {
public:
    bool judgeCircle(string moves) {
        int left = 0, down = 0;

        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'U') {
                down++;
            } else if (moves[i] == 'D') {
                down--;
            } else if (moves[i] == 'R') {
                left++;
            } else {
                left--;
            }
        }
        return (left == down && left == 0);
    }
};