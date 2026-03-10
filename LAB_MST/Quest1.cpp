#include <bits/stdc++.h>
using namespace std;

int minimumInitialEnergy(vector<vector<int>>& tasks) {
        
    sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    });
    int energy = 0;
    int initialEnergy = 0;
    for (auto &t : tasks) {
        int actual = t[0];
        int minimum = t[1];
        if (energy < minimum) {
            initialEnergy += (minimum - energy);
            energy = minimum;
        }
        energy -= actual;
    }
    return initialEnergy;
}
int main() {
    vector<vector<int>> tasks = {{1,2},{2,4},{4,8}};    
    cout << minimumInitialEnergy(tasks);
    return 0;
}
