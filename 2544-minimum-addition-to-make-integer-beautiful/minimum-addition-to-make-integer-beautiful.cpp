class Solution {
public:
   
    long long makeIntegerBeautiful(long long n, int target) {
        if(n==target){
            return 0;
        }
          int sum=0;
          long long val=n;
        while(n!=0){
            sum+=(n%10);
            n=n/10;
        }
        n=val;
        if(sum<=target){
            return 0;
        }
        // kitni digit ko compromise karna 
        int cnt=0;
        while(n!=0&&sum>=target){
            cnt++;
            sum-=(n%10);
            n=n/10;
        }

        long long num=1;
        int c=cnt;
        while(cnt>0){
            num*=10;
            cnt--;
        }
        
   

long long lastK = val % (long long)pow(10, c);

return num-lastK;
        

    }
};