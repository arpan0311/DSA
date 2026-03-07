class Solution {
public:
    int trap(vector<int>& height) {
        int count=0;
        int n=height.size();
        int i=0,j=0;
        vector<int>left;
        left.push_back(height[0]);
        for(int i=1;i<height.size();i++){
            left.push_back(max(left[i-1],height[i]));
        }
        vector<int>right(n,-1);
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(height[i],right[i+1]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int height0=min(left[i-1],right[i+1]);
            if(height[i]>height0){
                continue;
            }
            ans+=(height0-height[i]);
        }
        return ans;
    }
};