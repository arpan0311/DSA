class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int>answer(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        // 3 2 1 
        for(int i=0;i<nums.size();i++){
            answer.push_back(nums[i]);

        }
        return answer;
    }
};