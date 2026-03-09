#include <bits/stdc++.h>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>


void bfs(int u , vector<int>& vis , vector<vector<int>>& adj){

    queue<int> q;
    q.push(u);
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        for(auto j : adj[node]){
            if(!vis[j]){
                q.push(j);
                vis[j]=1;
            }
        }
    }
}

//1665c
void solve() {
    // Place your problem-solving logic here.
    int n , m;
    cin>> n>>m;
    vector<vector<int>> adj(n+1);
    for(int i =0;i<n;i++){
        int u , v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<int,int>>cn;
    int ans =0;
    vector<int>vis(n+1,0);
    for(int i =1;i<=n;i++){
        if(!vis[i]){
            if(i != 1){
                cn.push_back({i-1,i});
            }
            vis[i]=1;
            bfs(i, vis, adj);
            ans++;
        }
    }
    for(auto i : cn){
        cout<<i.first<<" "<<i.second;
    }
    cout<<endl;
    cout<<ans -1;
}
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}
