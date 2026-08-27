class Solution {
public:
    void dfs(vector<vector<int>>& answer, vector<vector<int>>& graph,
             vector<int> ans, int s) {
        if (s == graph.size() - 1) {
            answer.push_back(ans);
            return;
        }

        for (auto& it : graph[s]) {
            ans.push_back(it);
            dfs(answer, graph, ans, it);
            ans.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> answer;
        vector<int> ans = {0};
        dfs(answer, graph, ans, 0);
        return answer;
    }
};