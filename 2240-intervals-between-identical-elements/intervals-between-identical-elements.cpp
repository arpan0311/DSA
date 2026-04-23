class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        unordered_map<int, long long> hash;
        unordered_map<int, long long> count;
        vector<long long>answer(nums.size(),0);
        // total sum + count
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] += i;
            count[nums[i]]++;
        }

        unordered_map<int, long long> hash1;
        unordered_map<int, long long> count1;

        for (int i = 0; i < nums.size(); i++) {

            int x = nums[i];

            // LEFT
            long long left = count1[x] * i - hash1[x];

            // RIGHT
            long long right = (hash[x] - hash1[x]) - (count[x] - count1[x]) * i;

            answer[i] = left + right;

            // update prefix
            hash1[x] += i;
            count1[x]++;
        }

        return answer;
    }
};