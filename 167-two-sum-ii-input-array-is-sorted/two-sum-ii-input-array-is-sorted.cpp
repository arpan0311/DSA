class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<int>answer;
        while(i<j){
            if(nums[i]+nums[j]==target){
                answer.push_back(i+1);
                answer.push_back(j+1);
                return answer;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {};
    }
};