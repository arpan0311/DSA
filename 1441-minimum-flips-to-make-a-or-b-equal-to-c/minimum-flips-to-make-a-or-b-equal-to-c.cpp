class Solution {
public:
    string intToBinary(int a){
        string s="";
        while(a>0){
            s+=(a%2+'0');
            a=a/2;
        }
        reverse(s.begin(),s.end());
        return s;
    }

    int minFlips(int a, int b, int c) {
        int cnt=0;
        string s1=intToBinary(a);
        string s2=intToBinary(b);
        string s3=intToBinary(c);

        int maxLen = max({s1.length(), s2.length(), s3.length()});

        s1 = string(maxLen - s1.length(), '0') + s1;
        s2 = string(maxLen - s2.length(), '0') + s2;
        s3 = string(maxLen - s3.length(), '0') + s3;

        for(int i=0;i<s3.length();i++){
            if((s3[i]-'0') != ((s1[i]-'0') || (s2[i]-'0'))){
                if(s3[i]=='0'){
                    if(s2[i]=='1' && s1[i]=='1'){
                        cnt+=2;
                    }
                    else{
                        cnt++;
                    }
                }
                else{
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
