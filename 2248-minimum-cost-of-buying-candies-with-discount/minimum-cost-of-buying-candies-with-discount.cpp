class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size()==1){
            return cost[0];
        }
        int answer=0;
        sort(cost.begin(),cost.end());
        for(int i=cost.size()-1;i>=0;i=i-3){
            if(i==0){
                answer+=cost[i];
            }
            else{
answer+=(cost[i]+cost[i-1]);
            }
            
        }
        return answer;
    }
};