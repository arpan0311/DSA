class Solution {
public:
    void dfs(vector<vector<int>>& graph, int s, vector<int> temp,
             vector<vector<int>>& answer) {
        if (s == graph.size() - 1) {
            answer.push_back(temp);
            return;
        }
        // temp.push_back(s);
        for (auto& it : graph[s]) {
            temp.push_back(it);
            dfs(graph, it, temp, answer);
            temp.pop_back();
        }
        //  temp.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp = {0};
        vector<vector<int>> answer;
        dfs(graph, 0, temp, answer);
        return answer;
    }
};