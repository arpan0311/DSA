class Solution {
public:
    int robotSim(vector<int>& nums, vector<vector<int>>& o) {
        
        unordered_set<string> st;
        for(auto &it : o){
            string s = to_string(it[0]) + "_" + to_string(it[1]);
            st.insert(s);
        }

        pair<int,int> dir = {0,1}; // north
        int x = 0, y = 0;
        int maxD = 0;

        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] == -2){
                // left turn
                dir = {-dir.second, dir.first};
            }
            else if(nums[i] == -1){
                // right turn
                dir = {dir.second, -dir.first};
            }
            else{
                for(int step = 0; step < nums[i]; step++){
                    
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    string key = to_string(nx) + "_" + to_string(ny);

                    if(st.find(key) != st.end()){
                        break;
                    }

                    x = nx;
                    y = ny;

                    maxD = max(maxD, x*x + y*y);
                }
            }
        }

        return maxD;
    }
};