class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=i+1,n=nums.size();
          vector<vector<int>>answer;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i-1]==nums[i]){
                continue;
            }
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j=j+1;
                    while(j+1<k&&nums[j-1]==nums[j]){
                        j++;
                    }
                }
                else if(sum>0){
                     k=k-1;
                    while(k>j&&nums[k]==nums[k+1]){
                        k--;
                    }
                }
                else{
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    answer.push_back(temp);
                     j=j+1;
                    while(j+1<k&&nums[j-1]==nums[j]){
                        j++;
                    }
                     k=k-1;
                    while(k>j&&nums[k]==nums[k+1]){
                        k--;
                    }
                }
            }
           
        }
        return answer;
    }

};