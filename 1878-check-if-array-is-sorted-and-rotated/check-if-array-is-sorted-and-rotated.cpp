class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>answer(nums.begin(),nums.end());
        sort(answer.begin(),answer.end());
        if(answer==nums){
            return true;
        }
        int x=1;
        int n=nums.size();
        while(x<n){
            vector<int>temp(nums.begin(),nums.end());
            for(int i=0;i<n;i++){
                temp[i]=nums[(i+x)%n];
            }
            if(temp==answer){
                return true;
            }
            x++;
        }
        return false;
    }
};