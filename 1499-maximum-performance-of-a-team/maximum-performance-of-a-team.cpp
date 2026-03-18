class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>> v;
        priority_queue<int, vector<int>, greater<int>> pq;

        // store {efficiency, speed}
        for(int i = 0; i < n; i++) {
            v.push_back({efficiency[i], speed[i]});
        }

        long long sum = 0, ans = 0;
        // sort by efficiency
        sort(v.begin(), v.end());
        // traverse from highest efficiency → lowest
        for(int i = n - 1; i >= 0; i--) {
            sum += v[i].second;
            pq.push(v[i].second);
            // if size exceeds k → remove smallest speed
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum * v[i].first);
        }

        return ans % 1000000007;
    }
};