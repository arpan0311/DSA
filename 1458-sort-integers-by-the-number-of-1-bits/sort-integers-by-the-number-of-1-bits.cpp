class Solution {
public:
 int intToBinary(int a){
        string s="";
        while(a>0){
            s+=(a%2+'0');
            a=a/2;
        }
        reverse(s.begin(),s.end());
        int  cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                cnt++;
            }
        }
        return cnt;
    }
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2){
        if(p1.first==p2.first){
            return p1.second<p2.second;
        }
        return p1.first<p2.first;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>answer;
        for(int i=0;i<arr.size();i++){
                int val=intToBinary(arr[i]);
                answer.push_back({val,arr[i]});
        }
        sort(answer.begin(),answer.end(),cmp);
        for(int i=0;i<arr.size();i++){
            arr[i]=answer[i].second;
        }
        return arr;
    }
};