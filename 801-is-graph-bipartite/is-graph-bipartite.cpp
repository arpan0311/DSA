class Solution {
public:
    // bool dfs(vector<vector<int>>& graph, int s, int bit, vector<int>& vis) {
    //     vis[s] = bit;

    //     for (auto& it : graph[s]) {
    //         // not visited
    //         if (vis[it] == -1) {
    //             if (!dfs(graph, it, bit ^ 1, vis)) {
    //                 return false;
    //             }
    //         } else {
    //             if (vis[it] == bit) {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    bool bfs(vector<vector<int>>& graph, int s, int bit, vector<int>& vis) {

        queue<int> q;
        q.push(s);
        vis[s] = bit;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int nei : graph[node]) {

                if (vis[nei] == -1) {

                    vis[nei] = vis[node] ^ 1;
                    q.push(nei);

                } else if (vis[nei] == vis[node]) {

                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int bit = 1;
        int n = graph.size();
        vector<int> vis(n, -1);
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!bfs(graph, i, bit, vis)) {
                    return false;
                }
            }
        }
        return true;
    }
};