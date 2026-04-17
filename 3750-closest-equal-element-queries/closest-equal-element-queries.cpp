class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> hash;

        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]].push_back(i);
        }

        int n = nums.size();
        vector<int> answer(queries.size(), -1);

        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i];
            int val = nums[idx];

            auto& vec = hash[val];

            if (vec.size() < 2)
                continue;

            int sz = vec.size();

            // us walle index ki kya position hai ya current index ki ky indexing h
            //     iss array mein int pos =
                  int pos=  lower_bound(vec.begin(), vec.end(), idx) - vec.begin();

            int res = INT_MAX;

            int right = vec[(pos + 1) % sz];
            int d1 = abs(right - idx);
            res = min(res, min(d1, n - d1));

            int left = vec[(pos - 1 + sz) % sz];
            int d2 = abs(left - idx);
            res = min(res, min(d2, n - d2));

            answer[i] = res;
        }

        return answer;
    }
};