class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long sum=0;
        int i=0,j=0;
        // x-k element aara 
        unordered_map<long long,int>hash;// value and index
        long long answer=0;
        hash[0]=1;
        while(i<nums.size()){
            sum+=nums[i];
            if(hash.find(sum-k)!=hash.end()){
                answer+=hash[sum-k];
            }
            hash[sum]++;
            i++;
        }
        return answer;
    }
};