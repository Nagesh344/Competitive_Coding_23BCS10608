#include <bits/stdc++.h>
using namespace std;
void floydWarshall(vector<vector<int>> &dist, int V) {
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {

                if(dist[i][k] != 1e8 && dist[k][j] != 1e8)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

            }
        }
    }
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(dist[i][j] == 1e8)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {

    int V = 4;
    vector<vector<int>> dist = {
        {0,   5, 1e8, 10},
        {1e8, 0,   3, 1e8},
        {1e8, 1e8, 0,   1},
        {1e8, 1e8, 1e8, 0}
    };

    floydWarshall(dist, V);
}
