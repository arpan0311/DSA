class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>hash;
        for(auto&it:nums){
            if(hash.find(it)!=hash.end()){
                return it;
            }
            hash[it]++;
        }
        return -1;
    }
};