class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int profit =0,min_price=nums[0];
        for(int i=1;i<nums.size();i++){
            profit=max(profit,nums[i]-min_price);
            min_price=min(min_price,nums[i]);
        }
        return profit;
    }
};
// profit = sell - buy 
// inc -> sell 
// dec buy 