class Solution {
public:
    int minFlips(string s) {
        int k=s.length();
        s=s+s;
        int n=s.length();
        string s1="",s2="";
        for(int i=0;i<n;i++){
            if(i%2==0){
                s1+='1';
                s2+='0';
            }
            else{
                s1+='0';
                s2+='1';
            }
        }
        int j=0,i=0;
        int diff1=0,diff2=0;
        int answer=INT_MAX;
        while(j<n){
            if(s[j]!=s1[j]){
                diff1++;
            }
            else{
                diff2++;
            }
            if(j-i+1>k){
               if(s[i]!=s1[i]) diff1--;
                if(s[i]!=s2[i]) diff2--;
                i++;
            }

            if(j-i+1==k){
                answer=min(answer,min(diff1,diff2));
            }
            j++;
        }
        return answer;
    }
};