class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> freePQ;

        priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> busyPQ;

        vector<int> ans;

        for(int i=0;i<servers.size();i++)
        {
            freePQ.push({servers[i],i});
        }

        long long time=0;

        for(int i=0;i<tasks.size();i++)
        {
            time=max(time,(long long)i);

            if(freePQ.empty())
            {
                time=busyPQ.top().first;
            }

            while(!busyPQ.empty() && busyPQ.top().first<=time)
            {
                int idx=busyPQ.top().second;
                busyPQ.pop();

                freePQ.push({servers[idx],idx});
            }

            auto cur=freePQ.top();
            freePQ.pop();

            ans.push_back(cur.second);

            busyPQ.push(
            {
                time+tasks[i],
                cur.second
            });
        }

        return ans;
    }
};