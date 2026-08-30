class Solution {
public:
    // reverse logic
    unordered_set<string>vis;
    void rotate(string& s, int b) {
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
        reverse(s.begin(), s.end());
    }
    // addition logic
    int solve(char s, int a) { return (s - '0' + a) % 10; }

    void solve(string& s, int a, int b, string temp, string& res) {
        // base case
        if (res > temp) {
            res = temp;
        }
        if(vis.count(temp)){
            return;
        }
        // store curr condition...
        vis.insert(temp);
        // option1 rotate
        rotate(temp, b);
        solve(s, a, b, temp, res);
        // option 2 addition
        for (int i = 1; i < s.length(); i += 2) {
            temp[i] = (solve(temp[i], a)) + '0';
        }
        solve(s, a, b, temp, res);
    }
    string findLexSmallestString(string s, int a, int b) {
        string answer = s;
        string res = s;
        solve(s, a, b, answer, res);
        return res;
    }
};
