// grahm scan for convex hull

// Algo
// 1. sort the points by angle with respect to origin
// 2. select minimum y point and add it to convex hull
// 3. if y value  is same selct min x point and add it to convex hull
// 4. check left or right turn and if(turn is right pop previous line from convex hull)
// 5. join curr and prev point
// Andrew monotonic chain algo , more practical usage
#include <bits/stdc++.h>
using namespace std;
#define jack420                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

class point
{
public:
    int x, y;
    point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int check(point a, point b, point c){
    return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x -a.x));
}
void solve()
{
    // Place your problem-solving logic here.
    int n;
    cin >> n;
    vector<point> vv;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        point p = point(u,v);
        vv.emplace_back(p);
    }

    sort(vv.begin(), vv.end(), [](auto a , auto b){
        if(a.x == b.x)return a.y<b.y;
        return a.x<b.x;
    });

    vector<point> stk;
    for(int i =0;i<n;i++){
        if(stk.size()<2){
            stk.push_back(vv[i]);
        }
        else{
            while(stk.size()>1 && check(stk[stk.size()-2], stk.back(), vv[i]) < 0){
                stk.pop_back();
            }
            stk.push_back(vv[i]);
        }
    }

    set<pair<int,int>> s;
    for(auto i : stk){
        s.insert({i.x,i.y});
    }
    stk.clear();

    for(int i =n-1;i>=0;i--){
        if(stk.size()<2){
            stk.push_back(vv[i]);
        }
        else{
            while(stk.size()>1 && check(stk[stk.size()-2], stk.back(), vv[i]) < 0){
                stk.pop_back();
            }
            stk.push_back(vv[i]);
        }
    }
    for(auto i : stk){
        s.insert({i.x,i.y});
    }
    cout<<s.size()<<endl;
    for(auto i : s){
        cout<<i.first<<" "<<i.second<<endl;
    }
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
