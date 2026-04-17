class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int val1=INT_MIN,val2=INT_MIN;
        int cnt=0,cnt1=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0&&nums[i]!=val2){
                val1=nums[i];
                cnt++;
            }
            else if(cnt1==0&&nums[i]!=val1){
                val2=nums[i];
                cnt1++;
            }
            else if(nums[i]==val1){
                cnt++;
                // cnt1--;
            }
            else if(nums[i]==val2){
                // cnt--;
                cnt1++;
            }
            else{
                cnt--;
                cnt1--;
            }
          
        }

        int v1=0,v2=0;
        for(int i=0;i<nums.size();i++){
            if(val1==nums[i]){
                v1++;
            }
            else if(val2==nums[i]){
                v2++;
            }
        }                  
        cout<<val1<<" "<<val2<<" ";
        vector<int>answer;
        if(v1>=(nums.size()/3+1)){
            answer.push_back(val1);
        }
      if(v2>=(nums.size()/3+1)){
            answer.push_back(val2);
        }
        return answer;
    }
};