class Solution {
public:
    int minimumMoves(string s) {
        long long cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='X'){
                cnt++;
                i=i+2;
            }
        }
        return cnt;
    }
};