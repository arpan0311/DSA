class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = height[0], right = height[n - 1];
        long long maxarea = 0;
        int i = 0, j = height.size()-1;
        while (i < j) {
            int mini = min(height[i], height[j]);
            int area = (j - i) * mini;
            if (area > maxarea) {
                maxarea = area;
            }
            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxarea;
    }
};