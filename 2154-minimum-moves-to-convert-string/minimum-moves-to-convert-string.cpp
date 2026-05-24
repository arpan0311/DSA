class Solution {
public:
    int minimumMoves(string s) {
       int cnt =0;
       for(int i=0;i<s.length();i++){
            if(s[i]=='O'){
                continue;
            }
            if(s[i]=='X'){
                i=i+2;
                cnt++;
            }
       }
       return cnt;
    }
};