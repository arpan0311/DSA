class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& nums, int k) {
        int i = 0, j = +1;
        priority_queue<pair<int,pair<int, int>>>pq;
        int curr_val=nums[0][1]-nums[0][0];
        int ans=INT_MIN;
        pq.push({curr_val,{nums[0][0],nums[0][1]}});
        while (j < nums.size()) {
            while(!pq.empty()&&abs(nums[j][0]-pq.top().second.first)>k){
                pq.pop();
            }
              if (!pq.empty()) {
                int best = pq.top().first;
                int val = nums[j][0] + nums[j][1] + best;
                ans = max(ans, val);
            }
          
            pq.push({nums[j][1]-nums[j][0],{nums[j][0],nums[j][1]}});
            j++;
        }
        return ans;
    }
};