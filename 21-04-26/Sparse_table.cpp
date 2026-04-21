#include <bits/stdc++.h>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXI = 100'005;
int logr[MAXI];
int query(int l , int r, vector<vector<int>>& dp){

    //  query ->> l , r

    //  len = r - l + 1
    //  find prev power of 2 i.e j  is log2(len)
    //  return min( dp[l][(1<<j)] , dp[ r-  (1<<j) +1 ][j])

    int len = r - l + 1;
    // int k =0;

    //  log(n)  t.c but we need o(1) ********



    // while((1<<(k+1))<= len){
    //     k++;
    // }
    // int val = min(dp[i][k],dp[r-k+1][r] );
    // return val;

    // int k = 31 - __builtin_clz(len);
    int k = logr[len];  // use precomputed value , but can give precision error
    int val = min(dp[l][k],dp[r-(1<<k)+1][k]);
    return val;

}

void solve() {
    // Place your problem-solving logic here.
    int n ;
    cin >> n;

    logr[1] = 0;
    for(int i = 2; i <= n; i++){
        logr[i] = logr[i/2] +1;
    }
    vector<int> v(n);
    for(auto &x: v)cin>>x;

    //  5 , 6 , 8 , 4 , 1 , 2 , 9 , 10

    vector<vector<int>> dp (n, vector<int>(25,0));
    //  dp[i][j] = min(dp[i][j-1], dp[i+ (1<<(j-1)) ][j-1])

    for(int i =0 ; i< n ; i++){
        dp[i][0] = v[i];
    }
    for(int j = 1 ; j < 17; j++){
        for(int i = 0 ; i + (1<<j) -1 < n ; i++){
            dp[i][j] = min(dp[i][j-1], dp[i+ (1<<(j-1))][j-1]);
        }
    }

    int q;
    cin >> q;
    while(q--){
        //  process queries
    }


}
int32_t main() {
    int t=1;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}
