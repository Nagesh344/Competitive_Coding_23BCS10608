#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    const long long INF = 1e18;

    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);

    priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;

    dist[1] = 0;
    pq.push({0,1});

    while(!pq.empty()){

        pair<long long,int> top = pq.top();
        pq.pop();

        long long d = top.first;
        int node = top.second;

        if(d > dist[node]) continue;

        for(auto edge : adj[node]){

            int next = edge.first;
            int weight = edge.second;

            if(dist[node] + weight < dist[next]){
                dist[next] = dist[node] + weight;
                parent[next] = node;
                pq.push({dist[next], next});
            }
        }
    }

    if(dist[n] == INF){
        cout << -1;
        return 0;
    }
    vector<int> path;
    for(int v = n; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    for(int v : path)
        cout << v << " ";

    return 0;
}
