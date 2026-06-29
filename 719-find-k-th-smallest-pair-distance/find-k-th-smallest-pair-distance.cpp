class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

       int mx=*max_element(nums.begin(),nums.end());
       vector<int>answer(mx+1,0);
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                int diff=abs(nums[i]-nums[j]);
                answer[diff]++;
            }
        }

        for(int i=0;i<=mx;i++){
            k-=answer[i];
            if(k<=0){
                return i;
            }
        }       
        
        return -1;
    }
};