class Solution {
public:
    int tribonacci(int n) {

        int one =0,two=1,three=1;
        if(n==0){
            return 0;
        }
        if(n==1||n==2){
            return 1;
        }
        for(int i=3;i<=n;i++){
            int curr=one+two+three;
            one=two;
            two=three;
            three=curr;
        }
        return three;
    }
};