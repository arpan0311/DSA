class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // i>(i+k)k=
        int n=nums.size();
        k=k%n;
        vector<int>answer(n,0);

        for(int i=0;i<nums.size();i++){
            answer[(i+k)%n]=nums[i];
        }
        nums=answer;

    }
};