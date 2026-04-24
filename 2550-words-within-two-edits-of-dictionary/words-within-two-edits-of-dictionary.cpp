class Solution {
public:
    vector<string> twoEditWords(vector<string>& nums, vector<string>& nums1) {
        vector<string>answer;
        for(int i=0;i<nums.size();i++){
            string s=nums[i];
            for(int j=0;j<nums1.size();j++){
                int mismatch=0;
                for(int k=0;k<nums1[j].length();k++){
                    if(nums[i][k]!=nums1[j][k]){
                        mismatch++;
                    }
                }
                if(mismatch<3){
                    answer.push_back(s);
                    break;
                }
            }
        }
        return answer;
    }
};