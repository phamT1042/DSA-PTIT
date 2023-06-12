#include<bits/stdc++.h>
using namespace std;
int parent[1001], sz[1001];
void Make(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int Find (int u) {
    if (parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}
void Union (int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    parent[b] = a;
}
int main() {
    int T; cin >> T;
    while (T--) {
        int n, m, x, y; cin >> n >> m;
        Make(n);
        while (m--) {
            cin >> x >> y;
            Union(x, y);
        }
        int q; cin >> q;
        while (q--) {
            int s, t; cin >> s >> t;
            if (Find(s) == Find(t)) cout << "YES";
            else cout << "NO";
            cout << '\n';
        }
    }
    return 0;
}