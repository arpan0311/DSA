class Solution {
public:
   static bool cmp(pair<int,int>&p1,pair<int,int>&p2){
        if(p1.first==p2.first){
           return p1.second<p2.second;
        }
        return p1.first<p2.first;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>>answer;
        for(int i=0;i<intervals.size();i++){
            answer.push_back({intervals[i][1],intervals[i][0]});
        }
        sort(answer.begin(),answer.end(),cmp);
        int cnt=0;
        int end=answer[0].first,start=answer[0].second;
        for(int i=1;i<intervals.size();i++){
            cout<<answer[i].first<<" "<<answer[i].second<<endl;
            if(end<=answer[i].second){
                end=answer[i].first;
            }
            else{
                cnt++;
            }
        }
        return cnt;;
    }
};