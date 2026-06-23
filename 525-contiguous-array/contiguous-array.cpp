class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }
        // return the length of a subarray with sum 0;
        unordered_map<int, int> hash;
        int len = 0;
        int sum=0;
        hash[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (hash.find(sum) != hash.end()) {
                len = max(len, i - hash[sum] );
            } else {
                hash[sum] = i;
            }
        }
        return len;
    }
};