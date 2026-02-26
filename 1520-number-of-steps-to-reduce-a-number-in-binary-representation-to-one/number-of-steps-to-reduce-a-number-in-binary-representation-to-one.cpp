class Solution {
public:
    int numSteps(string s) {
        int step=0;
       while(s!="1") {
        if(s.back()=='0'){
            s.pop_back();
        }
        else{
            int n=s.length();
            int carry=1;
            for(int i=n-1;i>=0;i--){
                if(carry==1){
                    if(s[i]=='0'){
                        s[i]='1';
                        carry=0;
                    }
                   else {
                        s[i]='0';
                        carry=1;
                    }
                }
                else{
                    if(s[i]=='0'){
                        continue;
                    }
                    else{
                        s[i]=='1';
                        carry=0;
                    }
                }
            }
            if(carry==1){
                s.insert(0, 1, '1'); 
            }
        }
        step++;
       }
       return step;
    }
};