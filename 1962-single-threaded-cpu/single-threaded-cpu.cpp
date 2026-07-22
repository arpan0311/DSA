class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<array<int,3>> answer;
        for (int i = 0; i < n; i++) {
            int s = tasks[i][0], p = tasks[i][1], idx = i;
            answer.push_back({s, p, idx});
        }

        sort(answer.begin(), answer.end());

        vector<int> res;
        int idx = 0;

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        long long starting_time = 0;

        while (idx < n || !pq.empty()) {

            if (pq.empty() && starting_time < answer[idx][0]) {
                starting_time = answer[idx][0];
            }

            while (idx < n && answer[idx][0] <= starting_time) {
                pq.push({answer[idx][1], answer[idx][2]});
                idx++;
            }

            if (!pq.empty()) {
                auto p = pq.top();
                pq.pop();

                starting_time += p.first;
                res.push_back(p.second);
            }
        }

        return res;
    }
};