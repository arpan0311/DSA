class Solution {
 bool isPalindrome(string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
void print(string s,vector<vector<string>>&ans,vector<string> value,int i){
    // base case
    if(i==s.length()){
        ans.push_back(value);
        return;
    }
    string num="";
    for(int j=i;j<s.length();j++){
        num+=s[j];
        if(isPalindrome(num)){
            // function call
        value.push_back(num);
        print(s,ans,value,j+1);
            // backtracking 
        value.pop_back();
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
    vector<vector<string>>ans;
    vector<string>value;
    print(s,ans,value,0);
    return ans;
    }
};