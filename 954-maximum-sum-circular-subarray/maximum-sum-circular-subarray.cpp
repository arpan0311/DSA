class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxKadane = nums[0], currentMax = 0;
        int minKadane = nums[0], currentMin = 0;

        for (int num : nums) {
            currentMax = max(num, currentMax + num);
            maxKadane = max(maxKadane, currentMax);

            currentMin = min(num, currentMin + num);
            minKadane = min(minKadane, currentMin);

            totalSum += num;
        }

        // If all numbers are negative, totalSum == minKadane.
        if (maxKadane < 0) return maxKadane;

        return max(maxKadane, totalSum - minKadane);
    }
};
