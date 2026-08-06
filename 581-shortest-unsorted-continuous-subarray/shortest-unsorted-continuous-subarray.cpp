class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minii=INT_MAX,minij=INT_MIN;
        vector<int>answer(nums.begin(),nums.end());
        sort(answer.begin(),answer.end());
        for(int i=0;i<nums.size();i++){
            if(answer[i]!=nums[i]){
                minii=min(minii,i);
                minij=max(minij,i);
            }
        }
        if(minii==INT_MAX){
            return 0;
        }
        else if(minij==INT_MIN){
            return 0;
        }
        return minij-minii+1;
    }
};