class Solution {
public:
  int solve(int k, unordered_set<int>& st) {

        int ans = k;

        for(int i = 1; i * i <= k; i++) {

            if(k % i == 0) {

                
                if(st.count(i)) {
                    ans = min(ans, i);
                }

                int other = k / i;

                if(st.count(other)) {
                    ans = min(ans, other);
                }
            }
        }

        return ans;
    }

  
    long long minArraySum(vector<int>& nums) {
        unordered_set<int>st;

        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=solve(nums[i],st);
            sum+=nums[i];
        }
        return sum;
    }
};