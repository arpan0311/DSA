class Solution {
public:
    string solve(string &s, int &i) {
        string result = "";
        while(i < s.length() && s[i] != ']') {
            if(isdigit(s[i])) {
                int num = 0;
                while(i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                
                i++; // skip '['
                string temp = solve(s, i);
                
                i++; // skip ']'
                while(num--) {
                    result += temp;
                }
            }
            else {
                result += s[i];
                i++;
            }
        }
        
        return result;
    }

    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
};