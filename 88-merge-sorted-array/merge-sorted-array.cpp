class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>answer(m+n,0);

        int i=0,j=0,idx=0;
        while(i<m&&j<n){
            if(nums1[i]<nums2[j]){
                answer[idx]=nums1[i];
                i++;
            }
            else{
                answer[idx]=nums2[j];
                j++;
            }
            idx++;
        }

        while(i<m){
            answer[idx]=nums1[i];
            i++;
            idx++;
        }

        
        while(j<n){
            answer[idx]=nums2[j];
            j++;
            idx++;
        }
        nums1=answer;
    }
};