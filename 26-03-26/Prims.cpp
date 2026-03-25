#include <bits/stdc++.h>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void solve() {
    // Place your problem-solving logic here.
    int n , e ;
    cin >> n >> e ;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i =0; i < e ; i ++){
        int u , v, w;
        cin >> u >> v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int ans =0 ;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;

    pq.push({0,1});
    vector<int> vis(n+1,0);
    while(!pq.empty()){
        auto [dist , node] = pq.top();
        pq.pop();
        if(vis[node])continue;
        vis[node]=1 ;
        ans += dist;
        for(auto i: adj[node]){
            if(!vis[i.first]){
                pq.push({i.second , i.first});
            }
        }
    }
    cout<< ans ;
}
int32_t main() {
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}
