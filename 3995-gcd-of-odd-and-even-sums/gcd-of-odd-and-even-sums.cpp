class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        long long  odd=n*n;
        long long even=n*(n+1);
        if(even>odd){
            while(even%odd!=0){
                odd=even%odd;
            }
        }
        return odd;
    }
};