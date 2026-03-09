#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll BASE = 31;
const ll MOD = 1000000007;

vector<ll> power;

void precomputePowers(int maxLen) {
    power.resize(maxLen + 1);
    power[0] = 1;
    for (int i = 1; i <= maxLen; i++) {
        power[i] = (power[i - 1] * BASE) % MOD;
    }
}

ll computeHash(const string &s) {
    ll hash = 0;
    for (int i = 0; i < s.length(); i++) {
        ll val = (s[i] - 'a' + 1);
        hash = (hash + val * power[i]) % MOD;
    }
    return hash;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> dict(n);
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        cin >> dict[i];
        maxLen = max(maxLen, (int)dict[i].length());
    }

    precomputePowers(maxLen);

    unordered_set<ll> st;

    for (int i = 0; i < n; i++) {
        st.insert(computeHash(dict[i]));
    }

    for (int i = 0; i < m; i++) {
        string query;
        cin >> query;

        ll originalHash = computeHash(query);
        bool found = false;

        for (int j = 0; j < query.length(); j++) {
            char originalChar = query[j];
            ll originalVal = (originalChar - 'a' + 1);

            ll baseHash = (originalHash
                          - (originalVal * power[j]) % MOD
                          + MOD) % MOD;

            for (char ch : {'a', 'b', 'c'}) {
                if (ch == originalChar) continue;

                ll newVal = (ch - 'a' + 1);
                ll newHash = (baseHash + newVal * power[j]) % MOD;

                if (st.count(newHash)) {
                    cout << "YES\n";
                    found = true;
                    break;
                }
            }

            if (found) break;
        }

        if (!found) {
            cout << "NO\n";
        }
    }

    return 0;
}
