class StockPrice {
public:
    StockPrice() {

    }

    unordered_map<int, int> hash;
    set<pair<int, int>> st;
    int prev = -1;

    void update(int t, int price) {
    auto it = hash.find(t);

    if (it != hash.end()) {
        st.erase({it->second, t});
    }

    st.insert({price, t});
    hash[t] = price;
    prev = max(prev, t);
}

    int current() {
        return hash[prev];
    }

    int maximum() {
        return st.rbegin()->first;   
    }

    int minimum() {
        return st.begin()->first;    
    }
};