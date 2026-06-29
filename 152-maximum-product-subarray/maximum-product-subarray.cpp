class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long prefix=1,suffix=1;
        long long answer=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(prefix==0){
                prefix=1;
            }
            if(suffix==0){
                suffix=1;
            }
            prefix*=nums[i];
            suffix*=nums[nums.size()-i-1];
            answer=max(answer,max(prefix,suffix));
        }
        return answer;
    }
};