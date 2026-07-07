class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<pair<int,int>>st;
        vector<int>answer(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            if(st.empty()){
                st.push({nums[i],i});
            }
            else {
                
                while(!st.empty()&&st.top().first<=nums[i]){
                    st.pop();
                }
                 if(!st.empty()&&nums[i]<st.top().first){
                    answer[i]=st.top().second-i;
                }
                st.push({nums[i],i});  
            }
        }
        return answer;
    }
};