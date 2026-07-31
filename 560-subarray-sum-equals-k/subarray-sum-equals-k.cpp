class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int,int>hash;
        hash[0]=1;
        int i=0,j=0;
        int curr_sum=0;
        while(j<nums.size()){
            curr_sum+=nums[j];
            if(hash.find(curr_sum-k)!=hash.end()){
                cnt+=hash[curr_sum-k];
            } 
            hash[curr_sum]++;
            j++;
        }
        return cnt;
    }
};