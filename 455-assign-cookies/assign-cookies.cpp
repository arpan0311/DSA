class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int cnt=0;
        int i=0,j=0;
        while(i<g.size()&&j<s.size()){
            if(g[i]>s[j]){
                j++;
                continue;
            }
            else if(g[i]<=s[j]){
                i++;
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};