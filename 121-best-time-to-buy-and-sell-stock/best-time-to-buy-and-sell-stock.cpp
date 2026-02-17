class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_Profit=0;
        int minPrice=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minPrice=min(minPrice,prices[i]);
            max_Profit=max(max_Profit,prices[i]-minPrice);
        }
        return max_Profit;
    }
};