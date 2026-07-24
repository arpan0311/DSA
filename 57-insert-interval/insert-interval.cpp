class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>answer;
        for(int i=0;i<intervals.size();i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            int j=i+1;
            while(j<intervals.size()&&end>=intervals[j][0]){
                end=max(end,intervals[j][1]);
                j++;
            }
            i=j-1;
            vector<int>temp;
            temp.push_back(start);
            temp.push_back(end);
            answer.push_back(temp);
        }
        return answer;
    }
};