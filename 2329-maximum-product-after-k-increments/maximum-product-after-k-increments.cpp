class Solution {
public:
    const  int  mod=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        while(k>0&&!pq.empty()){
            int val=pq.top();
            val++;
            pq.pop();
            pq.push(val);
            k--;
        }
        long long sum=1;
        while(!pq.empty()){
            sum=(sum*pq.top())%mod;
            pq.pop();
        }
        return sum%mod;
    }
};