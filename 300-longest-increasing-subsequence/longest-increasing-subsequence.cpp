class Solution {
public:
    int binarySearch(vector<int>&temp,int target){
        int low=0,high=temp.size()-1;
        int value=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(temp[mid]>=target){
                value=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return  value;
    }
        int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        for(int i=0;i<nums.size();i++){
            if(temp.empty()||temp.back()<nums[i]){
                temp.push_back(nums[i]);
            }
            else {
                int ind=binarySearch(temp,nums[i]);
                temp[ind]=nums[i];
            }
        }
        return temp.size();
    }
};