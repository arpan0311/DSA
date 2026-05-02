class Solution {
public:
    int rotatedDigits(int n) {
         int cnt=0;
         for(int i=1;i<=n;i++){
            int val=i;
            bool can_make=false;
            while(val!=0){
                int digit=val%10;
                cout<<digit<<" ";
                if(digit==2||digit==5||digit==6||digit==9){
                   can_make=true;
                }
                else if(digit==4||digit==3||digit==7){
                    can_make=false;
                    break;
                }
                val=val/10;
            }
            if(can_make){
                cnt++;
            }
         }
         return cnt;
    }
};