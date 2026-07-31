class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // for(int i=0;i<gas.end();i++){
        //     gas.push_back(gas[i]);
        // }
        //       for(int i=0;i<cost.end();i++){
        //     cost.push_back(cost[i]);
        // }
        int n = gas.size();
        int need = accumulate(cost.begin(), cost.end(), 0);
        int curr = accumulate(gas.begin(), gas.end(), 0);
        if (curr < need) {
            return -1;
        }

        for (int j = 0; j < n; j++) {

            
            int value = 0;
            value += gas[j % n];
            value -= cost[(j) % n];
            if (value < 0) {
                continue;
            }
            int i = j+1;
            while (i < n) {
                value += gas[i % n];
                value -= cost[(i) % n];
                if (value < 0) {
                    break;
                }
                i++;
            }
            if (value >= 0) {
                return j;
            }
            j=i;
        }
        return -1;
    }
};