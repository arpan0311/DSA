class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            return (a-mass)<(b-mass);
        });
        for(int i=0;i<nums.size();i++){
            if(mass<nums[i]){
                return false;
            }
            if(mass>=1e5){
                continue;
            }
            mass+=nums[i];
        }
        return true;
    }
};