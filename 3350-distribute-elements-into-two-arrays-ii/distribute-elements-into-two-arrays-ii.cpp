#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

class Solution {
public:
    typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
                 tree_order_statistics_node_update>
        ordered_set;

    vector<int> resultArray(vector<int>& nums) {

        vector<int> ans, arr1, arr2;
        ordered_set s1, s2;
        arr1.push_back(nums[0]);
        s1.insert({nums[0], 0});
        arr2.push_back(nums[1]);
        s2.insert({nums[1], 1});

        for (int i = 2; i < nums.size(); i++) {
            int val = nums[i];
            int id1 = arr1.size() - s1.order_of_key({val + 1, -1});
            int id2 = arr2.size() - s2.order_of_key({val + 1, -1});

            if (id1 > id2) {
                arr1.push_back(nums[i]);
                s1.insert({nums[i], i});
            } else if (id1 < id2) {
                arr2.push_back(nums[i]);
                s2.insert({nums[i], i});
            } else {
                if (arr1.size() < arr2.size()) {
                    arr1.push_back(nums[i]);
                    s1.insert({nums[i], i});
                } else if (arr1.size() > arr2.size()) {
                    arr2.push_back(nums[i]);
                    s2.insert({nums[i], i});
                } else {
                    arr1.push_back(nums[i]);
                    s1.insert({nums[i], i});
                }
            }
        }
        ans = arr1;
        for (auto& val : arr2) {
            ans.push_back(val);
        }

        return ans;
    }
};