class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int k = 0; k <= 31; k++) {
            int temp = 1 << k;
            int one = 0;
            for (int i = 0; i < nums.size(); i++) {
                // woh wali bit 1 hai yani yahan pe change karna pedaga
                if ((nums[i] & temp) !=0 ) {
                    one++;
                }
            }
            // last mai ek one bachha h hamare pass
            if (one % 3 == 1) {
                result = result | temp;
            }
        }
        return result;
    }
};