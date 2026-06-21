class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt=0,money=0;
        for(int i=0;i<costs.size();i++){
            if(money+costs[i]<=coins){
                cnt+=1;
                money+=costs[i];
            }
        }
        return cnt;
    }
};