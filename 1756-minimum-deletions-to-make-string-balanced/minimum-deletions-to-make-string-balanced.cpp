class Solution {
public:
    int minimumDeletions(string s) {
        int cnta=0,cntb=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                cnta++;
            }
        }
        int n=s.size();
        int answer=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                cnta--;
            }
            int value=cntb+cnta;
            answer=min(answer,value);
            if(s[i]=='b'){
                cntb++;
            }
        }
            return answer;
    }
};