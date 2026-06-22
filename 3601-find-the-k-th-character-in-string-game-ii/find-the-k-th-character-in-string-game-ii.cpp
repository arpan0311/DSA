class Solution {
public:

    char kthCharacter(long long k, vector<int>& nums) {
        if(k==1){
            return 'a';
        }
        long long len=1;
        int operation=-1;
        for(int i=0;i<nums.size();i++){
            len=(long long)(len*2);
            if(len>=k){
                operation=nums[i];
                k=k-len/2;
                break;
            }
        }
        char ch=kthCharacter(k,nums);
        if(operation!=0){
            return (ch=='z') ? 'a': ch+1;
        }
        return ch;
    }
};