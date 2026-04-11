class Solution {
public:
    string decodeString(string s) {
        stack<char>st;

        for(int i=0;i<s.length();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else{
                // decode string 
                string curr="";
                // got all characters
                while(!st.empty()&&st.top()!='['){
                    curr+=st.top();
                    st.pop();
                }
                // [ ko hatao...
                if(!st.empty()){
                    st.pop();
                }
                reverse(curr.begin(),curr.end());
                string num="";
                // means digit h
                while(!st.empty()&&isdigit(st.top())){
                    num+=st.top();
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int val=stoi(num);
                string temp=curr;
                curr="";
                while(val>0){
                    curr+=temp;
                    val--;
                }
                for(auto&it:curr){
                    st.push(it);
                }
            }
        }
        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};