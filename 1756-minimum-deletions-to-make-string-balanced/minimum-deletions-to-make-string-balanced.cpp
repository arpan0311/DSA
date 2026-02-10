class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(st.empty()||(st.top()=='a'&&s[i]=='a'||s[i]=='b')||st.top()=='b'&&s[i]=='b'){
                st.push(s[i]);
            }
            else if(st.top()=='b'&&s[i]=='a'){
                if(!st.empty()&&st.top()=='b'&&s[i]=='a'){
                    cnt++;
                    st.pop();
                }
            }
           
           
    }
        return cnt;
    }
};