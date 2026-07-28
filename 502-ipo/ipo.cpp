class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<pair<int, int>> answer;

        for (int i = 0; i < profits.size(); i++) {
            answer.push_back({capital[i], profits[i]});
        }

        sort(answer.begin(), answer.end());

        priority_queue<int> pq;

        int res = 0;
        int i = 0;
        while (k--) {

            while (i < answer.size() && w >= answer[i].first) {
                pq.push(answer[i].second);
                i++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};