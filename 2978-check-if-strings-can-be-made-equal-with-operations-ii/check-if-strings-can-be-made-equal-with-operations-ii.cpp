class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int>odd,odd2,even,even2;

        for(int i=0;i<s1.length();i=i+2){
            even[s1[i]]++;
        }
         for(int i=1;i<s1.length();i=i+2){
            odd[s1[i]]++;
        }

        
        for(int i=0;i<s2.length();i=i+2){
            even2[s2[i]]++;
        }
         for(int i=1;i<s2.length();i=i+2){
            odd2[s2[i]]++;
        }
        return odd==odd2&&even==even2;
    }
};