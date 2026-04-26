class Solution {
public:
   static bool cmp(const pair<pair<int,char>,int>& p,
                const pair<pair<int,char>,int>& q) {

    if (p.first.first == q.first.first) {
        return p.second < q.second; 
    }
    return p.first.first > q.first.first; 
                }
    string sortVowels(string s) {
        unordered_map<char, int> hash;
        unordered_map<int,int>start;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                    if(start.find(s[i])==start.end()){
                        start[s[i]]=i;
                    }
                hash[s[i]]++;
            }
            
        }
        vector<pair<pair<int, char>, int>> ans;

        for (auto& it : hash) {
           ans.push_back({{it.second, it.first}, start[it.first]});
        }

        sort(ans.begin(), ans.end(),cmp);
      
        int i = 0;
        string  answer="";
        while (i < s.length()) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                for (int j = 0; j < 5; j++) {
                    if (ans[j].first.first > 0) {
                        answer.push_back(ans[j].first.second);
                        ans[j].first.first--;
                        break;
                    }
                }
            }
            else{
                answer.push_back(s[i]);
            }
            i++;
        }
        return answer;
    }
};