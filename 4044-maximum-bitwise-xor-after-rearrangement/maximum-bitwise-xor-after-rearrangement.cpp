class Solution {
public:
    string maximumXor(string s, string t) {
        int zero=0,one=0;
        string answer="";

        for(int i=0;i<t.length();i++){
            if(t[i]=='0'){
                zero++;
            }
            else{
                one++;
            }
        }

        for(int i=0;i<t.length();i++){
            if(s[i]=='0'){
                if(one>=1){
                    one--;
                    answer+='1';
                }
                else{
                    zero--;
                    answer+='0';
                }

            }
            else{
                if(zero>=1){
                    zero--;
                    answer+='1';
                }
                else{
                    one--;
                    answer+='0';
                }
            }
        }
        return answer;
    }
};