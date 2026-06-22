class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        int left_max=0,right_max=0;
        int l=0,r=n-1;
        int answer=0;
        while(l<r){
            left_max=max(left_max,nums[l]);
            right_max=max(right_max,nums[r]);
            if(left_max<right_max){
                answer+=(left_max)-nums[l];
                l++;
            }
            else{
                answer+=(right_max)-nums[r];
                r--;
            }
        }
        return answer;
    }
};