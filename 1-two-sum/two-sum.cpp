class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hash;
        for(int i=0;i<nums.size();i++){
            int rest_value=target-nums[i];
            if(hash.find(rest_value)!=hash.end()){
                return {hash[rest_value],i};
            }
            hash[nums[i]]=i;
        }
        return {-1,-1};
    }
};