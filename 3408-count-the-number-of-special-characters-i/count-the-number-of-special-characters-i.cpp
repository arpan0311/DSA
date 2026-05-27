class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> hash;
        int cnt = 0;

        for (int i = 0; i < word.size(); i++) {

            bool istrue = false;

            // check lowercase
            if (word[i] >= 'a' && word[i] <= 'z') {
                istrue = false;
            }
            else {
                istrue = true;
            }

            char ch;

            if (istrue) {
                ch = tolower(word[i]);
            }
            else {
                ch = toupper(word[i]);
            }

            if (hash.find(ch) != hash.end()&&hash[word[i]]==0) {
                cnt++;
            }

            hash[word[i]]++;
        }

        return cnt;
    }
};