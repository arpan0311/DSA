class Solution {
public:
// int dp[1001];
//     int  arpan(vector<int>&cost,int i){

//         if(i>=cost.size()){
//             return 0;
//         } 
//         if(dp[i]!=-1){
//             return dp[i];
//         }
//         int one=cost[i]+arpan(cost,i+1);
//         int two=cost[i]+arpan(cost,i+2);
//         dp[i]=min(one,two);
//         return dp[i];
//     }   
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==2){
            return min(cost[0],cost[1]);
        }
        int answer=0;

      for(int i=2;i<cost.size();i++){;
      cost[i]= cost[i] + min(cost[i-1], cost[i-2]);

      }

      return min(cost[n-1],cost[n-2]);
    }
};