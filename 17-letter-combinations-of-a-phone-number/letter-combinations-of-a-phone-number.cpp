class Solution {
public:
    void solve(string &digits,int i,string curr,vector<string>&res,unordered_map<char,vector<char>>&answer){
        // base case 
        if(i==digits.size()){
            res.push_back(curr);
            return;
        }

        for(auto&it:answer[digits[i]]){
            if(it==answer[digits[i]].back()){
                curr.push_back(it);
                solve(digits,i+1,curr,res,answer);
            }
            else{
                curr.push_back(it);
                solve(digits,i+1,curr,res,answer);
                curr.pop_back();
            }
        }

    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> answer;
         for (char x = 'a'; x <= 'c'; x++) {
            answer['2'].push_back(x);
        }
        
          for (char x = 'd'; x <= 'f'; x++) {
            answer['3'].push_back(x);
        }
        for (char x = 'g'; x <= 'i'; x++) {
            answer['4'].push_back(x);
        }
        for (char x = 'j'; x <= 'l'; x++) {
            answer['5'].push_back(x);
        }
         for (char x = 'm'; x <= 'o'; x++) {
            answer['6'].push_back(x);
        }
          for (char x = 'p'; x <= 's'; x++) {
            answer['7'].push_back(x);
        }
        for (char x = 't'; x <= 'v'; x++) {
            answer['8'].push_back(x);
        }
        for (char x = 'w'; x <= 'z'; x++) {
            answer['9'].push_back(x);
        }

        vector<string>temp;
        int i=0;
        string curr="";
        solve(digits,i,curr,temp,answer);
        return temp;
    }
    };