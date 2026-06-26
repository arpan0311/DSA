class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // max sum of size 5
        if(nums.size()==0){
            return 0;
        }
        double answer = INT_MIN;
        long long sum = 0;
        int n = nums.size();
        int i = 0, j = 0;
        while (j < n) {
            sum += nums[j];

            if (j - i + 1 == k) {
              double avg = (double)sum / k;
                answer = max(answer, avg);
                 sum -= nums[i];
                 i++;
            }
            j++;
        }
        return answer;
    }
};