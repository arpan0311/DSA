class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<pair<int,int>>answer; //value,index

            for(int i=0;i<nums.size();i++){
                answer.push_back({nums[i],i});
            }
            int i=0;
            while(i<nums.size()){
                if(nums[i]!=0){
                    i++;
                    continue;
                }
                if(nums[i]==0){
                    // we have to find num[j] it doesn't 
                    int j=i+1;
                    while(j!=nums.size()&&nums[j]==0){
                        j++;
                    }
                    if(j<nums.size()){
                        swap(nums[i],nums[j]);
                    }
                }

               i++;
            }

    }
};