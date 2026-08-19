class Solution {
public:
    bool solve(unordered_set<int>& st, int s) {
        return !st.count(s) && !st.count(s + 1) && !st.count(s + 2) &&
               !st.count(s + 3);
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        int cnt = 0;
        unordered_map<int, unordered_set<int>> nums;

        for (int i = 0; i < res.size(); i++) {
            nums[res[i][0]].insert(res[i][1]);
        }

        cnt += ((n - nums.size()) * 2);

        for (auto& it : nums) {
            bool first = solve(it.second, 2);
            bool sec = solve(it.second, 4);
            bool third = solve(it.second, 6);
            if (first && third) {
                cnt += 2;
            } else if (first || sec || third) {
                cnt++;
            }
        }
        return cnt;
    }
};