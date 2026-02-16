class Solution {
public:
    string intToBinary(int a){
        string s="";
        while(a>0){
            s+=(a%2+'0');
            a=a/2;
        }
        while(s.length()!=32){
            s+='0';
        }
        reverse(s.begin(),s.end());
        return s;
    }
    long long BinaryToint(string s){
        long long  sum=0;
        long long val=1;
        int n=s.length()-1;

        while(n>=0){
          sum += val * (s[n] - '0');
            val=val*2;
            n--;
        }
        return sum;
    }
    int reverseBits(int n) {
        string s=intToBinary(n);
        reverse(s.begin(),s.end());
        long a=BinaryToint(s);

        return a;
    }
};