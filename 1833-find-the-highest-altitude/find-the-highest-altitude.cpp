class Solution {
public:
    int largestAltitude(vector<int>& gain) {
          int c = 0;
        int h = 0;
        for (int altitudeGain : gain) {
            c += altitudeGain;
            h = max(h, c);
        }
        
        return h;
    }
};