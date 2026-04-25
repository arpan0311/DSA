class Solution {
public:
    bool validDigit(int n, int x) {
        unordered_map<int,int>hash;
        string s=to_string(n);
        if(s[0]==x+'0'){
            return false;
        }
        while(n!=0){
            int digit=n%10;
            hash[digit]++;
            n=n/10;
        }

        return hash[x]>=1;
    }
};