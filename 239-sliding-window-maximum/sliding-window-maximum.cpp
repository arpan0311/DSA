class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<int>result;

        for(int i=0;i<nums.size();i++){
            // ek to empty na ho sath hi sath usme space bnane ke liye 
            while(!dq.empty()&&dq.front()<=i-k){
                dq.pop_front();
            }
            // 4 2 3 6 ->3->2->4-> order hoga ye 
            while(!dq.empty()&&nums[i]>nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            // push to our result vector
            if(i>=k-1){
                result.push_back(nums[dq.front()]);
            }
        }
            return result;
    }
};