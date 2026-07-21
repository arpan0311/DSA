class Solution {
public:
    int furthestBuilding(vector<int>& nums, int b, int l) {
        priority_queue<int> pq;
        //  priority_queue<int> pq;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 < nums.size()) {
                if (nums[i + 1] <= nums[i]) {
                    cnt++;
                    continue;
                } else {
                    // hamarase pass bricks  hain
                    int diff = nums[i + 1] - nums[i];
                    // to use kar liya  bricks ka...
                    if (diff <= b) {
                        b -= diff;
                        pq.push(diff);
                        cnt++;
                    } else if (l > 0) {

                        if (!pq.empty() && pq.top() > diff) {
                            b += pq.top();
                            b -= diff;
                            pq.pop();
                            pq.push(diff);
                        }

                        l--;
                        cnt++;
                    } else {
                        break;
                    }
                }
            }
        }

        return cnt;
    }
};