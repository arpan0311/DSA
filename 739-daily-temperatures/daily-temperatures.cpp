class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<pair<int,int>>st;
        vector<int>answer(nums.size(),0);
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({nums[i],i});
            }
            else{
                
                while(!st.empty()&&nums[i]>=st.top().first){
                    st.pop();
                }
                
                if(!st.empty()){
                    answer[i]=st.top().second-i;
                }
                st.push({nums[i],i});
            }
        }
        return answer;
    }
};