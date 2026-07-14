class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    set<pair<int, int>> hash,db;
    bool book(int s, int e) {
        if (hash.empty()) {
            hash.insert({s, e});
            return true;
        } else {
            // check overlapp
             for(auto&it:db){
                 if(e<=it.first||s>=it.second){
                    continue;
                }
                else{
                   return false;
                }
            }

            for (auto& it : hash) {
                if(e<=it.first||s>=it.second){
                    continue;
                }
                else{
                   int s1=max(s,it.first);
                   int e1=min(e,it.second);
                   db.insert({s1,e1});
                   cout<<s1<<" "<<e1<<endl;
                } 
            }

           
            hash.insert({s,e});  
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */