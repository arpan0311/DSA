class Solution {
public:
    string solve(string s, int cnt, int steps) {
        if (cnt == 0) {
            reverse(s.begin(), s.end());
            return s;
        }
        char c = 'a' + steps;
        if (c == 'z') {
            s += string(cnt, 'z');
            reverse(s.begin(), s.end());
            return s;
        }
        if (cnt % 2 == 1) {
            s += c;
        }
        return solve(s, cnt / 2, steps + 1);
    }

    vector<string> largestString(vector<int>& nums) {
        vector<string> answer;

        for (int x : nums) {
            answer.push_back(solve("", x, 0));
        }

        return answer;
    }
};