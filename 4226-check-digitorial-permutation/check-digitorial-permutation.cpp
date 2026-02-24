class Solution {
public:
    long long facto[10];
    void compute(){
        facto[0]=1;
        for(int i=1;i<10;i++){
            facto[i]=facto[i-1]*i;
        }
    }
    bool isDigitorialPermutation(int n) {
        compute();
        int sum=0;
        int  val=n;
        vector<int>first;
        while(n!=0){
            int digit=n%10;
            first.push_back(digit);
            sum+=facto[digit];
            n=n/10;
        }
        vector<int>sec;
        while(sum!=0){
            int digit=sum%10;
            sec.push_back(digit);
            sum=sum/10;
        }
        if(first.size()!=sec.size()){
            return false;
        }
        sort(first.begin(),first.end());
        sort(sec.begin(),sec.end());
                return first==sec;
    }
};