class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int prev=0,curr=0;
        long long answer=0;
        for(int i=0;i<target.size();i++){
            curr=target[i];
            if(curr<prev){
                prev=curr;
                continue;
            }
            answer+=(curr-prev);
            prev=curr;
        }
        return answer;
    }
};