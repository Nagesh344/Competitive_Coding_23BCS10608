class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adjList(n+1);
        for(int i=0;i<times.size();i++){
            adjList[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>time(n+1,1e9);
        time[0]=0;
        time[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto[t,node]=pq.top();
            pq.pop();
            if(time[node]<t) continue;
            for(int i=0;i<adjList[node].size();i++){
                int addT=adjList[node][i].second;
                int neigh=adjList[node][i].first;
                if(time[neigh]>addT+t){
                    time[neigh]=addT+t;
                    pq.push({addT+t,neigh});
                }
            }
        }
        int ans=-1;
        for(int i=0;i<time.size();i++){
            if(time[i]==1e9) return -1;
            ans=max(ans,time[i]);
        }
        return ans;
    }
};
