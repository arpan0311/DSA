class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }

    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& nums, int fs, int fe) {

        sort(nums.begin(), nums.end(), cmp);

        int n = nums.size();
        vector<vector<int>> merged;

        // Merge overlapping + touching intervals
        for (int i = 0; i < n;) {
            int s = nums[i][0];
            int e = nums[i][1];

            int j = i + 1;

            while (j < n && nums[j][0] <= e + 1) {
                e = max(e, nums[j][1]);
                j++;
            }

            merged.push_back({s, e});
            i = j;
        }

        vector<vector<int>> answer;   // Fixed

        for (auto &it : merged) {
            int start = it[0], end = it[1];

            if (fe < start || fs > end) {
                answer.push_back({start, end});   // Fixed
            }
            // pura overlap
            else if (start >= fs && end <= fe) {
                continue;
            }
            else if (start < fs && end > fe) {
                answer.push_back({start, fs - 1});
                answer.push_back({fe + 1, end});
            }
            else if (start < fs) {
                answer.push_back({start, fs - 1});   // Fixed
            }
            else {
                answer.push_back({fe + 1, end});     // Fixed
            }
        }

        return answer;   // Fixed
    }
};