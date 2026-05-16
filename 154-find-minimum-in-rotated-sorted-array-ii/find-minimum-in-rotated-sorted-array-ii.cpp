class Solution {
public:
    int findMin(vector<int>& nums) {
        
        vector<int>answer;
        answer.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                answer.push_back(nums[i]);
            }
        }
        for(int i=0;i<answer.size();i++){
            cout<<answer[i]<<" ";
        }
        int last=answer.size()-1;
        int low=0,high=answer.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            // means we are in first past 
            if(answer[mid]>=answer[last]){
                 ans=min(ans,answer[mid]);
                low=mid+1;
            }
            
            else {
                ans=min(ans,answer[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};