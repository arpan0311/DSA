class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> ch(26, 0);

        for (int i = 0; i < tasks.size(); i++) {
            ch[tasks[i] - 'A']++;
        }

        sort(ch.begin(), ch.end());

        int max_frec = ch[25];
        int gaddha = max_frec - 1;
        int idal_slot = n * gaddha;
        for (int i = 24; i >= 0; i--) {
            idal_slot -= min(gaddha, ch[i]);
        }
        if (idal_slot > 0) {
            return idal_slot + tasks.size();
        }
        return tasks.size();
    }
};