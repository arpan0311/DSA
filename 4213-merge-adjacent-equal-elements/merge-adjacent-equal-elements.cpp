class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> answer;

        for (int i = 0; i < nums.size(); i++) {
            if (answer.empty()) {
                answer.push_back(nums[i]);
            } else {
                long long curr = nums[i];
                while (!answer.empty() && answer.back() == curr) {
                    curr *= 2;
                    answer.pop_back();
                }
                answer.push_back(curr);
            }
        }
        return answer;
    }
};