/*
 // Definition for Employee.
 class Employee {
 public:
     int id;
     int importance;
     vector<int> subordinates;
 };
*/

class Solution {
public:
    void bfs(unordered_map<int, vector<int>>& hash,
             int& answer,
             int id,
             unordered_map<int, int>& imp) {

        unordered_set<int> vis;
        queue<int> q;

        vis.insert(id);
        q.push(id);
        answer += imp[id];

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& it : hash[node]) {
                if (!vis.count(it)) {
                    answer += imp[it];
                    q.push(it);
                    vis.insert(it);
                }
            }
        }
    }

    int getImportance(vector<Employee*> employees, int id) {

        unordered_map<int, vector<int>> hash;
        unordered_map<int, int> imp;

        for (auto& it : employees) {
            hash[it->id] = it->subordinates;
            imp[it->id] = it->importance;
        }

        int answer = 0;

        bfs(hash, answer, id, imp);

        return answer;
    }
};