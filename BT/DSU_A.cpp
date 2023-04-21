#include<bits/stdc++.h>
using namespace std;
int parent[100001], sz[100001];
int n, m, res;
void make_set() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    res = max(res, sz[a]);
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        res = 0;
        make_set();
        while (m--) {
            int x, y; cin >> x >> y;
            union_set(x, y);
        }
        cout << res << '\n';
        memset(parent, 0, sizeof(parent));
        memset(sz, 0, sizeof(sz));
    }
    return 0;
}