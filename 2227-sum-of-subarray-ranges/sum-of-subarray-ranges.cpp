class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>pSe(n,-1),nGe(n,n),pGe(n,-1),nSe(n,n);
        stack<pair<int,int>>st;
        // previous small element ka index chaiye merko
        for(int i=0;i<nums.size();i++){
                if(st.empty()){
                    st.push({nums[i],i});
                }
                else{
                    while(!st.empty()&&st.top().first>=nums[i]){
                        st.pop();
                    }
                    if(!st.empty()){
                        pSe[i]=st.top().second;
                    }
                    st.push({nums[i],i});
                }
        }

      while (!st.empty()) {
    st.pop();
}
        // next greater element 
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({nums[i],i});
            }
            else{
                while(!st.empty()&&st.top().first<nums[i]){
                    st.pop();
                }
                if(!st.empty()){
                    nGe[i]=st.top().second;
                }
                st.push({nums[i],i});
            }
        }
        // previous greater 
      while (!st.empty()) {
    st.pop();
}

        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({nums[i],i});
            }
            else{
                while(!st.empty()&&nums[i]>=st.top().first){
                    st.pop();
                }
                if(!st.empty()){
                    pGe[i]=st.top().second;
                }
                st.push({nums[i],i});
            }
        }

        // next smaller
       while (!st.empty()) {
    st.pop();
}
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({nums[i],i});
            }
            else{
                while(!st.empty()&&nums[i]<st.top().first){
                    st.pop();
                }
                if(!st.empty()){
                    nSe[i]=st.top().second;
                }
                st.push({nums[i],i});
            }
        }

        // maximum sum
        long long answer=0;
        for(int i=0;i<n;i++){
            long long maxi=(long long)(nGe[i]-i)*(i-pGe[i])*nums[i];
            long long mini=(long long)(nSe[i]-i)*(i-pSe[i])*nums[i];
            answer+=(maxi-mini);
        }
        return answer;

    }
};