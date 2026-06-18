class Solution {
public:

const int mod=1e9+7;

    int numOfSubarrays(vector<int>& arr) {

        // number of  sumarray  with odd sum
        // odd number must be present odd times
        vector<int>prev(arr.size(),0);
        prev[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            prev[i]=prev[i-1]+arr[i];
        }
       int odd=0,even=1;
       long long cnt=0;
       arr=prev;
       for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0){
                cnt+=(odd);
                even++;
            }
            else{
                cnt+=(even);
                odd++;
            }
            cnt=cnt%mod;
       }
        return cnt;
    }
};