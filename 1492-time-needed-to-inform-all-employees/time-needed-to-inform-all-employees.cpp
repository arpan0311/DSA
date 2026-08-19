class Solution {
public:
    int bfs(int s, unordered_map<int, vector<int>> tree, int& maxi,
            unordered_map<int, int>& taken_time, int curr_time) {
        maxi = max(maxi, curr_time);
        queue<pair<int, int>> q;
        q.push({s, 0});
        int min_time_taken = 0;
        while (!q.empty()) {
            int st = q.front().first;
            int curr_taken_time = q.front().second;
            q.pop();
            min_time_taken = max(min_time_taken, curr_taken_time);
            for (auto& it : tree[st]) {
                q.push({it, curr_taken_time + taken_time[it]});
            }
        }
        return min_time_taken;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        unordered_map<int, vector<int>> tree;

        unordered_map<int, int> taken_time;
        for (int i = 0; i < manager.size(); i++) {
            tree[manager[i]].push_back(i);
        }

        for (int i = 0; i < informTime.size(); i++) {
            taken_time[i] = informTime[i];
        }
        // start dfs from tree[-1]
        int maxi = 0;
        return bfs(-1, tree, maxi, taken_time, 0);
    }
};