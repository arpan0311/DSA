class Solution {
public:
    int inttobinary(int n){
        int cnt=0;
        while(n!=0){
            if(n%2!=0){
                cnt++;
            }
            n=n/2;
        }
        return cnt;
    }
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>ans;
        for(int i=0;i<arr.size();i++){
            int val=inttobinary(arr[i]);
            ans.push_back({val,arr[i]});
        }
        int n=ans.size();
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0;i<n;i++){
            arr[i]=ans[i].second;
        }
        return arr;
    }
};