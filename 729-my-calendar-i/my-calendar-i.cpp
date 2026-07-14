class MyCalendar {
public:
    // struct pair_hash {
    //     size_t operator()(const pair<int, int>& p) const {
    //         return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    //     }
    // };
    // unordered_map<pair<int, int>, int> hash;

    MyCalendar() {
        // set<pair<int,int>>hash;
    }
    set<pair<int, int>> hash;
    bool book(int s, int e) {
        if (hash.empty()) {
            hash.insert({s, e});
            return true;
        } else {
            for (auto& it : hash) {
                if(e<=it.first||s>=it.second){
                    continue;
                }
                else{
                    return false;
                } 
            }
            hash.insert({s, e});
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */