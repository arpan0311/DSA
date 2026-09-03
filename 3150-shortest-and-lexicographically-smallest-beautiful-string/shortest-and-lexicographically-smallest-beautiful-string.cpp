class Solution {
public:
    string solve(string a,string b){
        if(a.length()==b.length()){
            if(a<b){
                return a;
            }
        }
        else if(a.length()<b.length()){
            return a;
        }
        return b;
    }
    string shortestBeautifulSubstring(string s, int k) {
        string answer=s;
        answer+=s;
        int i=0,j=0;
        int cnt=0;
        while(j<s.length()){
            int val=s[j]-'0';
            cnt+=val;
            while(cnt>k){
                cnt-=(s[i]-'0');
                i++;
            }
            while(cnt==k){
                string temp=s.substr(i,j-i+1);
                answer=solve(temp,answer);
                cnt-=(s[i]-'0');
                i++;
            }
            j++;
        }
        return answer.length()>s.length()?"":answer;
    }
};