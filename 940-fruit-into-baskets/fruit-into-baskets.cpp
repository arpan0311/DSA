class Solution {
public:
    int totalFruit(vector<int>& nums) {
        
        int i=0,j=0;
        int max_fruits=0;
        unordered_map<int,int>hash;
        while(j<nums.size()){
            hash[nums[j]]++;
            while(hash.size()>=3){
                if(hash[nums[i]]==1){
                    hash.erase(nums[i]);
                }
                else{
                    hash[nums[i]]--;
                }
                i++;
            }
            if(hash.size()>=1){
                max_fruits=max(max_fruits,j-i+1);
            }
            j++;
        }
        return max_fruits;
    }
};