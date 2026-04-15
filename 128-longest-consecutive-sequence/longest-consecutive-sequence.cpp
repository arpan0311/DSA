class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>hash(nums.begin(),nums.end());
        int maxi=0;
        for(auto&it:hash){
            // start a sequence 
            if(hash.find(it-1)==hash.end()){
                int curr=it;
                int cnt=1;
                while(hash.find(curr+1)!=hash.end()){
                    curr++;
                    cnt++;
                }
                maxi=max(maxi,cnt);
            }

        }
        return maxi;
    }
};