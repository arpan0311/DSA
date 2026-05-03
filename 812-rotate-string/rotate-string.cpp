class Solution {
public:
    bool rotateString(string s, string g) {
        if(s.length()!=g.length()){
            return false;
        }
        return (s + s).find(g) != string::npos;
    }
};