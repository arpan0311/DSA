class Solution {
public:
    long long binarytoint(string &s){
        long long num=0;
        int i=s.length()-1;
        long long cnt=1;
        while(i>=0){
            if(s[i]=='1'){
                num+=cnt;
            }
            cnt=cnt*2;
            i--;
        }
        return num;
    }
    int int_string(int n){
        string s="";
        while(n!=0){
            if(n%2==0){
                s+='0';
            }
            else{
                s+='1';
            }
            n=n/2;
        }
        reverse(s.begin(),s.end());
        int i=0;
        while(i<s.length()){
            if(s[i]=='1'){
                s[i]='0';
            }
            else{
                s[i]='1';
            }
            i++;
        }
       return binarytoint(s);
    }
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        return int_string(n);
    }
};