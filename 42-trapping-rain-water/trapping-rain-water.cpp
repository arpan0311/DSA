class Solution {
public:
    int trap(vector<int>& nums) {
        int left_max=0,right_max=0;
        int answer=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            left_max=max(left_max,nums[i]);
            right_max=max(right_max,nums[j]);
            if(left_max<=right_max){
                answer+=(left_max)-nums[i];
                i++;
            }
            else{
                answer+=(right_max)-nums[j];
                j--;
            }
        }
        return answer;
    }
};