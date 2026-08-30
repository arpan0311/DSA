class Solution {
public:
    char convert(char c){
        if(c=='a'){
            return 'z';
        }
        return c-1;
    }
    string smallestString(string s) {
    //    must h I have to perform a operation atleast... 
        bool  can_do=false;
        for(int i=0;i<s.length();i++){
            if(s[i]!='a'){
                s[i]=convert(s[i]);
                can_do=true;
            }
            else if(i==s.length()-1&&!can_do){
                s[i]=convert(s[i]);
            }
            else if(can_do){
                return  s;
            }
        }
        return s;
    }
};