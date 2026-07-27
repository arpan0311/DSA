class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // better approacch for this question 
        set<int>st;// all the element in sorted order 
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        // simple case 
        if(*st.begin()>1){
            return 1;
        }
        int k=0;
        for(auto&it:st){
            if(it<=k){
                continue;
            }
            else if(it==k+1){
                k++;
            }
            else{
                return k+1;
            }
        }
        return k+1;
    }
};