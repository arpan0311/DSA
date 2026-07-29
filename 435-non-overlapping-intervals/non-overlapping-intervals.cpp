class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        // same end time 
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // two option sort using start time or end time
        // now I got the point I have to sort it on behalf of end time

        sort(intervals.begin(), intervals.end(),cmp);
        int cnt = 0;
        int i = 0;
        while (i < intervals.size()) {
            int end_time = intervals[i][1];
            int j = i + 1;
            // remove overlap condition
            while(j<intervals.size()&&end_time>intervals[j][0]){
                cnt++;
                j++;
            }
            i = j;
        }
        return cnt;
    }
};