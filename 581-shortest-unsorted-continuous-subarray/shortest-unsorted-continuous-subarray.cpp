class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minii = INT_MAX, minij = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 < nums.size() && nums[i] > nums[i + 1]) {
                minii = min(minii, i);
                minij = max(minij, i + 1);
            }
        }

        if (minii == INT_MAX) {
            return 0;
        } else if (minij == INT_MIN) {
            return 0;
        }

        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=minii;i<=minij;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }

        int curr_value = nums[minii];
        int i = minii;

        while (i >= 0) {
            if (nums[i] > mini) {   
                minii = i;
            }
            i--;
        }

        curr_value = nums[minij];
        i = minij;

        while (i < nums.size()) {
            if (nums[i] < maxi) {   
                minij = i;
            }
            i++;
        }

        return minij - minii + 1;
    }
};