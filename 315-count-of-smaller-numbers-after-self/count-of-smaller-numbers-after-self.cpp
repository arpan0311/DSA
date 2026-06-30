class Solution {
public:
    int n;
    vector<int>bit;
    int query (int id){
        int ans=0;
        while(id>0){
            ans+=bit[id];
            id-=(id&-id);
        }
        return ans;
    }
    void update(int val,int id){
        while(id<=n){
            bit[id]+=val;
            id+=(id&-id);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
      
        n=nums.size();
        if(n==0){
            return {};
        }
        bit.assign(n + 1, 0);
        vector<pair<int,int>>sorted;
        for(int i=0;i<nums.size();i++){
            sorted.push_back({nums[i],i});
        }
        sort(sorted.begin(),sorted.end());
        vector<int>answer(n,0);
        for(auto&[el,id]:sorted){
            update(1,id+1);// har bar value 1 rahegi...
        
            answer[id]=query(n)-query(id+1);
        }
        return answer;
    }
};