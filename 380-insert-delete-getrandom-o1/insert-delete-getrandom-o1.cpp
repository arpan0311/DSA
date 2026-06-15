class RandomizedSet {
public:
    unordered_set<int>st;
    vector<int>nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.count(val)==0){
            st.insert(val);
            nums.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        int ind=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                ind=i;
                break;
            }
        }
        if(ind!=-1){
 nums.erase(nums.begin()+ind);
        }
       
        if(st.count(val)==1){
            st.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int val=rand()%nums.size();
        return nums[val];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */