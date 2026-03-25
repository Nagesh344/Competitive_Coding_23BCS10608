#include <bits/stdc++.h>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void solve() {
    // Place your problem-solving logic here.
    int n , m ;
    cin >> n >> m ;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 0 ; i < m ; i++ ){
        int u , v, w;
        cin >> u>>v;
        adj[u].push_back({v,w});
    }

    // fordfulkerson

    for(int i = 1 ; i < m ; i ++){
        if(!vis)
    }

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
