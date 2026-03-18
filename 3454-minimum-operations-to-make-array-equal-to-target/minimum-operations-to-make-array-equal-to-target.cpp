class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        vector<int>answer(n,0);

        for(int i=0;i<nums.size();i++){
            answer[i]=target[i]-nums[i];
        }

        long long result=abs(answer[0]);
        int prev=answer[0];
        int curr=0;
        for(int i=1;i<answer.size();i++){
            curr=answer[i];
            //  opposite 
            if(prev<=0&&curr>=0||prev>=0&&curr<=0){
                result+=abs(answer[i]);
                prev=curr;
                continue;
            }
            else if(prev<=0&&curr<=0){
                // both negetive
                if(prev<=curr){
                    prev=curr;
                    continue;
                } 
                result+=abs(curr-prev);
                prev=curr;
                continue;
            }
            else{
                // both positive 
                if(prev>=curr){
                    prev=curr;
                    continue;
                }
                result+=(curr-prev);
                prev=curr;
            }
        }
        return result;
    }
};