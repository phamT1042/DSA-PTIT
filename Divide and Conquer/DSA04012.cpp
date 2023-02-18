#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int p[n], q[m], r[n + m - 1];
        for (int &x : p) cin >> x;
        for (int &x : q) cin >> x;
        for (int i = 0; i < n + m - 1; i++) r[i] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                r[i + j] += p[i] * q[j];
            }
        }
        for (int x : r) cout << x << ' ';
        cout << endl;
    }
}