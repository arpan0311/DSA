class Solution {
public:
 // using dp
    int solve(vector<int>& prices, int i, int mini, int &maxProfit) {
        if (i == prices.size()) {
            return 0;
        }
        mini=min(mini,prices[i]);
        maxProfit=max(maxProfit,prices[i]-mini);
        solve(prices,i+1,mini,maxProfit);
        
        return maxProfit;
    }
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int mini=prices[0];
         solve(prices,0,mini,maxProfit);
        return maxProfit;
    }
};