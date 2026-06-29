class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int>answer;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                int diff=abs(nums[i]-nums[j]);
                answer.push_back(diff);
            }
        }
        
    
        nth_element(answer.begin(),answer.begin()+(k-1),answer.end());
        return answer[k-1];
    }
};