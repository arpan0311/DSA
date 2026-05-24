class Solution {
public:
    bool isChar(char ch){
        return ch>='a'&&ch<='z';
    }
    bool ischar(char ch){
        return ch>='A'&&ch<='Z';
    }
    bool isdigit(char ch){
        return  ch>='0'&&ch<='9';
    }
    int passwordStrength(string s) {
        long long cnt=0;
        unordered_set<char>st;
        for(int i=0;i<s.length();i++){
            if(st.count(s[i])){
                continue;
            }
            if(isChar(s[i])){
                cnt+=1;
            }
            else if(ischar(s[i])){
                cnt+=2;
            }
            else if(isdigit(s[i])){
                cnt+=3;
            }
            else{
                char ch=s[i];
                if(ch=='!'||ch=='@'||ch=='#'||ch=='$'){
                   cnt+=5;
                }

            }
            st.insert(s[i]);
        }
        return cnt;
    }
};