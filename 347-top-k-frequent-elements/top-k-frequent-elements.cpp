class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        vector<int>answer;
        // top k yani max to min heap leni padegi na...
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto&it:hash){
            pq.push(it.second);
            while(pq.size()>k){
                pq.pop();
            }
        }
        unordered_map<int,int>frec;
        while(!pq.empty()){
            frec[pq.top()]++;
            pq.pop();
        }
        for(auto&it:hash){
            if(frec.find(it.second)!=frec.end()){
                answer.push_back(it.first);
            }
        }
        return answer;
    }
};