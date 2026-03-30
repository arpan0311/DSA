class Solution {
public:

    const int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>pSe(arr.size(),-1),nSe(arr.size(),n);
        stack<int>st;

        for(int i=0;i<arr.size();i++){
                while(!st.empty()&&arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(!st.empty()){
                    pSe[i]=st.top();
                }
            
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
                while(!st.empty()&&arr[i]<arr[st.top()]){
                    st.pop();
                }
                if(!st.empty()){
                    nSe[i]=st.top();
                }
            
            st.push(i);
        }

        long long ans=0;
        for(int i=0;i<arr.size();i++){
           long long left = i - pSe[i];
            long long right = nSe[i] - i;
            long long contribution = (left * right) % mod;
            contribution = (contribution * (arr[i] % mod)) % mod;
            ans = (ans + contribution) % mod;
        }
        return ans;
    }
};