class Solution {
public:
    // I have to divide a number into a interval from   right such that in each
    // step num=a+b minimum step to do that job
    long long minimumReplacement(vector<int>& nums) {
        long long answer = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                continue;
            }
            int parts = nums[i] / nums[i + 1];
            if ((nums[i] % nums[i + 1]) !=0) {
                parts++;
            }
            // steps equal to parts -1 
            answer +=(parts-1);
            nums[i] = nums[i] / parts;
        }
        return answer;
    }
};