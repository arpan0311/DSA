class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]-=i;
        }
        // find max sum nums[i]+nums[j]
        int maxi=nums[0],answer=0;
        for(int i=1;i<nums.size();i++){
            answer=max(answer,maxi+nums[i]);
            maxi=max(maxi,nums[i]+2*i);
        }
        return answer;
    }
};