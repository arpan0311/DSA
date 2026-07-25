class Solution {
public:
    bool xorGame(vector<int>& nums) {
          int xor1 = 0;

        for (int num : nums) {
            xor1 ^= num;
        }

        // Alice wins if the total XOR is already 0, 
        // or if she starts with an even number of elements.
        return xor1 == 0 || nums.size() % 2 == 0;
    }
};