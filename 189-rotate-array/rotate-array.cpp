class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>answer(nums.begin(),nums.end());
        int n=nums.size();
        k=k%n;
        for(int i=0;i<nums.size();i++){
            nums[i]=answer[(i-k+n)%n];
        }
    }
};