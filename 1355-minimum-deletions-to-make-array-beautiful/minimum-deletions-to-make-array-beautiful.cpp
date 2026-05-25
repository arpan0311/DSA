class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            // even index
            if((i-cnt)%2==0){
                if(nums[i]==nums[i+1]){
                    cnt++;
                }
            }
        }
        if((nums.size()-cnt)%2==0){
            return cnt;
        }
        return cnt+1;
    }
};