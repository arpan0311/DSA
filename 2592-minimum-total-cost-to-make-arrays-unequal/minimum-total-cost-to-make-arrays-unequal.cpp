class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
         int n = nums1.size();
    unordered_map<int, int> freq;

    long long cost = 0;
    int totalSwaps = 0;
    int dominant = -1, domCount = 0;

   
    for (int i = 0; i < n; i++) {
        if (nums1[i] == nums2[i]) {
            cost += i;          
            totalSwaps++;
            freq[nums1[i]]++;

            if (freq[nums1[i]] > domCount) {
                domCount = freq[nums1[i]];
                dominant = nums1[i];
            }
        }
    }

  
    for (int i = 0; i < n; i++) {
        if (domCount * 2 <= totalSwaps) break;  

        if (nums1[i] == nums2[i]) continue;   

      
        if (nums1[i] != dominant && nums2[i] != dominant) {
            cost += i;
            totalSwaps++;
        }
    }

  
    if (domCount * 2 > totalSwaps) return -1;

    return cost;
    }
};