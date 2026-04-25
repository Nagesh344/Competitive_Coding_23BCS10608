#include <bits/stdc++.h>
using namespace std;
long long computeHash(string s) {
    const int p = 31;
    const int m = 1e9 + 7;
    long long hash = 0;
    long long power = 1;
    for (char c : s) {
        int val = c - 'a' + 1;
        hash = (hash + val * power) % m;
        power = (power * p) % m;
    }
    return hash;
}

int main() {
    string s = "geeksforgeeks";
    cout << "Output is: "<<computeHash(s);
}
