class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks,
                                     vector<string>& queries) {

        string s = "";

        for (auto& it : chunks) {
            s += it;
        }

        unordered_map<string, int> hash;

        string temp = "";

        int n = s.length();

        for (int i = 0; i < n; i++) {

            if (s[i] == '-') {
                if (i + 1 < n &&
                    i - 1 >= 0 &&
                    s[i - 1] >= 'a' && s[i - 1] <= 'z' &&
                    s[i + 1] >= 'a' && s[i + 1] <= 'z') {
                    temp += s[i];
                }
                else {

                    if (!temp.empty()) {
                        hash[temp]++;
                        temp = "";
                    }
                }
            }

            else if (s[i] == ' ') {

                if (!temp.empty()) {
                    hash[temp]++;
                    temp = "";
                }
            }

            else {
                temp += s[i];
            }
        }

        if (!temp.empty()) {
            hash[temp]++;
        }

        vector<int> answer;

        for (auto& it : queries) {
            answer.push_back(hash[it]);
        }

        return answer;
    }
};