class Solution {
public:
    static bool cmp(pair<int,int>& p1, pair<int,int>& p2) {
        return (p1.first * p1.first + p1.second * p1.second) <
               (p2.first * p2.first + p2.second * p2.second);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<pair<int,int>> answer;

        for (int i = 0; i < points.size(); i++) {
            answer.push_back({points[i][0], points[i][1]});
        }

        sort(answer.begin(), answer.end(), cmp);

        vector<vector<int>> result;
        
        int cnt = 0;

        for (auto &it : answer) {
            vector<int> ans;
            if (cnt == k) break;
            ans.push_back(it.first);
            ans.push_back(it.second);
            result.push_back(ans);
            cnt++;
        }

        // result.push_back(ans);
        return result;
    }
};
