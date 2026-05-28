class Solution {
public:
    
    using pii = pair<int,int>;

    long long totalCost(vector<int>& nums, int k, int candidates) {

        long long cost = 0;

        int n = nums.size();

        priority_queue<pii, vector<pii>, greater<pii>> left, right;

        int l = 0;
        int r = n - 1;

        // fill left heap
        for(int i = 0; i < candidates && l <= r; i++) {
            left.push({nums[l], l});
            l++;
        }

        // fill right heap
        for(int i = 0; i < candidates && l <= r; i++) {
            right.push({nums[r], r});
            r--;
        }

        for(int i = 0; i < k; i++) {

            if(right.empty() || 
              (!left.empty() && left.top().first <= right.top().first)) {

                auto it = left.top();
                left.pop();

                cost += it.first;

                if(l <= r) {
                    left.push({nums[l], l});
                    l++;
                }
            }

            else {

                auto it = right.top();
                right.pop();

                cost += it.first;

                if(l <= r) {
                    right.push({nums[r], r});
                    r--;
                }
            }
        }

        return cost;
    }
};