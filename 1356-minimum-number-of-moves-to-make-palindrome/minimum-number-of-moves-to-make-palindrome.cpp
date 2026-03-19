class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int i = 0, j = s.length() - 1;
        long long cnt = 0;

        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                // find match for s[i] from right side
                int ind = j;
                while (ind > i && s[ind] != s[i]) {
                    ind--;
                }

                if (ind == i) {
                    
                    swap(s[i], s[i + 1]);
                    cnt++;
                } else {
                    // bring match to position j
                    while (ind < j) {
                        swap(s[ind], s[ind + 1]);
                        cnt++;
                        ind++;
                    }
                    i++;
                    j--;
                }
            }
        }
        return cnt;
    }
};