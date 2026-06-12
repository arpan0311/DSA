class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_map<int,int>hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        long long val=1;
        while(1){
            if(hash.find(val)==hash.end()){
                return val;
            }
            val=val*2;
        }
        return val;
    }   
};