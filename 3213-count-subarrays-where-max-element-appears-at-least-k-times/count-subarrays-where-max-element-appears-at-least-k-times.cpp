class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long answer=0;
        int i=0,j=0;
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        unordered_map<int,int>hash;
        while(j<nums.size()){
            hash[nums[j]]++;
            while(i<n&&hash[maxi]>=k){
                answer+=(n-j);
                hash[nums[i]]--;
                i++;
            }
            j++;
        }
        return answer;
    }
};