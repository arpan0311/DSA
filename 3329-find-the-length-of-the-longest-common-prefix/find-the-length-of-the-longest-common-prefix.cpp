class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;
        for(int i=0;i<arr1.size();i++){
            while(!st.count(arr1[i])&&arr1[i]>0){
                st.insert(arr1[i]);
                arr1[i]=arr1[i]/10;
            }
        }
        int res=0;
        for(int i=0;i<arr2.size();i++){
             while(!st.count(arr2[i])&&arr2[i]>0){
                arr2[i]=arr2[i]/10;
            }
            if(arr2[i]>0){
                res=max(res,(int)log10(arr2[i])+1);
            }
        }
        return res;
    }
};