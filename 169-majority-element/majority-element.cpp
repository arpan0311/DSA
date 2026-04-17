class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int answer=nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==answer){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt<0){
                cnt=1;
                answer=nums[i];
            }
        }
        return answer;
    }
};