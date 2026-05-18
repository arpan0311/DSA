class Solution {
public:
    // int bfs(vector<int>& arr, int i, vector<bool>& vis, unordered_map<int,
    // vector<int>>& hash) {
    //     if (i < 0 || i >= (int)arr.size()) {
    //         return INT_MAX;
    //     }

    //     if (i == (int)arr.size() - 1) {
    //         return 0;
    //     }

    //     vis[i] = true;

    //     int take1 = INT_MAX;
    //     int take2 = INT_MAX;
    //     int take3 = INT_MAX;

    //     if (i + 1 < (int)arr.size() && !vis[i + 1]) {
    //         int val = bfs(arr, i + 1, vis, hash);
    //         if (val != INT_MAX) {
    //             take1 = 1 + val;
    //         }
    //     }

    //     if (i - 1 >= 0 && !vis[i - 1]) {
    //         int val = bfs(arr, i - 1, vis, hash);
    //         if (val != INT_MAX) {
    //             take2 = 1 + val;
    //         }
    //     }

    //     for (auto& it : hash[arr[i]]) {
    //         if (i != it && !vis[it]) {
    //             int val = bfs(arr, it, vis, hash);
    //             if (val != INT_MAX) {
    //                 take3 = min(take3, 1 + val);
    //             }
    //         }
    //     }

    //     vis[i] = false;

    //     return min(take1, min(take2, take3));
    // }

    int minJumps(vector<int>& arr) {
        vector<bool> vis(arr.size(), false);
        unordered_map<int, vector<int>> hash;

        for (int i = 0; i < (int)arr.size(); i++) {
            hash[arr[i]].push_back(i);
        }
        int steps = 0;
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int n = arr.size();
        while (!q.empty()) {

            int size = q.size();

            while (size > 0) {

                int idx = q.front();
                if (idx == n - 1) {
                    return steps;
                }
                q.pop();
                if (idx + 1 <= n - 1 && !vis[idx + 1]) {
                    vis[idx + 1] = true;
                    q.push(idx + 1);
                }
                if (idx - 1 >= 0 && !vis[idx - 1]) {
                    vis[idx - 1] = true;
                    q.push(idx - 1);
                }

                for (auto& it : hash[arr[idx]]) {
                    if (idx != it && !vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
                hash[arr[idx]].clear();
                size--;
            }

            steps++;
        }
        return -1;
    }
};