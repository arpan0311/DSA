#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<long long, null_type, less_equal<long long>,
             rb_tree_tag,
             tree_order_statistics_node_update> oset;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int l, int u) {
        oset os;
        os.insert(0);

        long long sum = 0;
        int cnt = 0;

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            int x = os.order_of_key(sum - l + 1);
            int y = os.order_of_key(sum - u);
            cnt += (x - y);
            os.insert(sum);
        }
        return cnt;
    }
};