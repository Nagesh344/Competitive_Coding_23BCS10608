#include <bits/stdc++.h>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

vector<int> segt;
void build(vector<int>&v , int idx , int low , int high){
    if(low == high){
        segt[idx] = v[low];
        return ;
    }

    int mid = low + (high - low)/2;
    build(v, 2*idx +1 , low , mid);
    build(v, 2* idx + 2 , ,mid+1, high);

    segt[idx] = max(segt[2*idx+1], segt[2*idx+2]);
}

int query(int idx , int l , int r , int low , int high){
    if(low > r || high < l){
        return INT_MIN;
    }

    if( low >= l and r >= high){
        return segt[idx];
    }
    int mid = low + (high - low)/2;
    int left = query(2*idx +1 ,l , r, low , mid);
    int right = query(2*idx +2 , l, r, mid+1,  high);
    return max(left , right);
}

void solve() {
    // Place your problem-solving logic here.

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto i : v)cin >>i;
    segt.resize(4*n);
    build(v, 0, 0, n-1);




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
