class Solution {
public:
    int solve(vector<int>&nums,int d){
        // I need no pairs that has minimum or equal to distance d ye hi hain na...
        int i=0,j=1;
        int pair=0;
        while(j<nums.size()){
            int dis=nums[j]-nums[i];
            while(nums[j]-nums[i]>d){
                i++;
            }

            pair+=(j-i);// no of pairs that we need to add 
            j++;
        }
        return pair;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=nums[n-1]-nums[0];
        int answer=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int pair=solve(nums,mid);
            if(pair<k){
                low=mid+1;
            }
            else{
                answer=mid;// store answer
                high=mid-1; 
            }
        }
        // answer to distance hai naa 
        return answer;
    }
};