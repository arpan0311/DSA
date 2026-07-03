class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        int n=nums.size();
        int time=(n+1)/2;
        for(auto&it:hash){
            if(it.second>=time){
                return it.first;
            }
        }
        return -1;
    }
};