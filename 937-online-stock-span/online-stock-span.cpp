class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(!st.empty()){
            int cnt=1;
            while(!st.empty()&&st.top().first<=price){
                cnt+=st.top().second;
                st.pop();
            }
            st.push({price,cnt});
            return cnt;
        }
        st.push({price,1});
        return 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */