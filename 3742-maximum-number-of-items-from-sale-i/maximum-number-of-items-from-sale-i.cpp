class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        unordered_map<int,int> hash;
        for(auto& it : items) hash[it[0]]++;

        vector<pair<int,int>> answer; 
        for(int i = 0; i < items.size(); i++){
            int cnt = 0, curr = items[i][0];
            for(int j = 1; j * curr <= 1500; j++){
                if(hash.count(j * curr))
                    cnt += hash[j * curr];
            }
          
            answer.push_back({items[i][1], cnt});
        }

        
        vector<vector<array<int,2>>> dp(
            budget+1, 
            vector<array<int,2>>(answer.size()+1, {0,0})
        );
     
        for(int money = 0; money <= budget; money++){
            for(int i = (int)answer.size()-1; i >= 0; i--){
                for(int cp = 0; cp <= 1; cp++){
                    // skip
                    int res = dp[money][i+1][1]; // skip always resets canpick=true
                    
                    // take and stay
                    if(money >= answer[i].first){
                        int gain = cp ? answer[i].second : 1;
                        int rem = money - answer[i].first;
                        res = max(res, gain + dp[rem][i][0]);
                    }
                    
                    // take and move  
                    if(money >= answer[i].first){
                        int gain = cp ? answer[i].second : 1;
                        int rem = money - answer[i].first;
                        res = max(res, gain + dp[rem][i+1][1]);
                    }
                    
                    dp[money][i][cp] = res;
                }
            }
        }
        
        return dp[budget][0][1];
    }
};