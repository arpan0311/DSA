class Solution {
private:
int square_finder(int n){
    int sum=0;
    while(n>0){
        int digit=n%10;
        sum+=digit*digit;
        n=n/10;
    }
    return sum;
}
public:
    bool isHappy(int n) {
        unordered_set<int>cycle;
        while(n!=1 && cycle.find(n)==cycle.end()){
            cycle.insert(n);
            n=square_finder(n);
        }
        return n==1;// means true else false apne aap chala jayega...
    }
};