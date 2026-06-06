class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int cnt=0;
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                if(s[i]<=s[j]){
                    s[j]=s[i];
                }
                else{
                    s[i]=s[j];
                }
            }
            i++;
            j--;
        }
        return s;
    }
};