class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>lower(26,-1),upper(26,-1);
        // last occurrence of lower and first occurrence of uppper case
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(islower(ch)){
                lower[ch-'a']=i;
            }
            else if(isupper(ch)&&upper[ch-'A']==-1){
                upper[ch-'A']=i;
            }
        }

        // dono mein available + lower[i]<upper[i]
        int count=0;
        for(char ch=0;ch<26;ch++){
            if(lower[ch]!=-1&&upper[ch]!=-1&&lower[ch]<upper[ch]){
                count++;
            }
        }
        return count;
    }
};