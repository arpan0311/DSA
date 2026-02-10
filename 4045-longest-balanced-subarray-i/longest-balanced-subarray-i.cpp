class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        // no of unique odd interger equal to number of even interger;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>odd,even;
            for(int j=i;j<nums.size();j++){
                    if(nums[j]%2!=0){
                        odd[nums[j]]++;
                    }
                    else{
                        even[nums[j]]++;
                    }
                if(odd.size()==even.size()){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};