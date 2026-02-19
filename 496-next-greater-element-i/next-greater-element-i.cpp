class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>ans(nums2.size(),-1);
        int n=nums2.size();
        for(int j=n-1;j>=0;j--){
            if(st.empty()){
                st.push(nums2[j]);
            }
            else {
                while(!st.empty()&&st.top()<nums2[j]){
                    st.pop();
                }
                if(!st.empty()&&st.top()>nums2[j]){
                    ans[j]=st.top();
                }
                st.push(nums2[j]);
            }
        }
            unordered_map<int,int>hash;
            for(int i=0;i<ans.size();i++){
                hash[nums2[i]]=ans[i];
            }
            vector<int>answer;
            for(int i=0;i<nums1.size();i++){
                if(hash.find(nums1[i])!=hash.end()){
                    answer.push_back(hash[nums1[i]]);
                }
            }

        return answer;
    }
};