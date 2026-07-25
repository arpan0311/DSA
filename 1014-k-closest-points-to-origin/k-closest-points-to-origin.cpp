class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int, vector<vector<int>>> hash;
        for (int i = 0; i < points.size(); i++) {
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            hash[dis].push_back(points[i]);
        }
        int i=0;
        vector<vector<int>>answer;
        for(auto&it:hash){
            if(i==k){
                return answer;
            }
            for(auto&itx:it.second){
                answer.push_back(itx);
                i++;
            }
            
        }
        return answer;
    }
};