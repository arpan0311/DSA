class Solution {

public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int jumps=0;
        while(r<nums.size()-1){
            int fouthermost=0;
            for(int i=l;i<=r;i++){
                fouthermost=max(i+nums[i],fouthermost);
            }
            jumps++;
            l=r+1;
            r=fouthermost;
        }
        
        return jumps;
    }
};