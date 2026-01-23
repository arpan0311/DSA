class Solution {
public:
vector<int>previous_Small(vector<int>& heights){
        int n=heights.size();
        // I need the index of previous small element 
        vector<int>ans(n,-1);
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({heights[i],i});
            }
            else if(st.top().first>heights[i]){
                if(st.top().first>heights[i]){
                    while(!st.empty()&&st.top().first>heights[i]){
                        int ind=st.top().second;
                        ans[ind]=i;
                        st.pop();
                    }
                    st.push({heights[i],i});
                }
            }
            else{
                st.push({heights[i],i});
            }
        }
        return ans;
    }

      vector<int>next_Small(vector<int>& height){
        int n=height.size();
        // I need the index of previous small element 
        vector<int>ans(n,n);
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({height[i],i});
            }
            else if(st.top().first>height[i]){
                    while(!st.empty()&&st.top().first>height[i]){
                        int ind=st.top().second;
                        ans[ind]=i;
                        st.pop();
                    }
                    st.push({height[i],i});
            }
            else{
                st.push({height[i],i});
            }
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>previous=previous_Small(heights);
        vector<int>next=next_Small(heights);
        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            int len=next[i]-previous[i]-1;
            maxArea=max(maxArea,(int)len*heights[i]);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0'){
                    sum=0;
                }
                ans[i][j]=sum;
            }
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,largestRectangleArea(ans[i]));
        }
        return maxArea;
    }
};