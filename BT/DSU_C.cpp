#include<bits/stdc++.h>
using namespace std;
int parent[101], sz[101];
int n, m, res;
struct edge {
    int x, y, w;
    edge (int a, int b, int c) {
        x = a; y = b; w = c;
    }
};
vector<edge> dsCanh;
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
bool union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        make_set();
        int a, b, c;
        while (m--) {
            cin >> a >> b >> c;
            dsCanh.push_back(edge(a, b, c));
            dsCanh.push_back(edge(b, a, c));
        }
        sort(dsCanh.begin(), dsCanh.end(), [](edge a, edge b) {return a.w < b.w;});
        int cntMST = 0, d = 0;
        for (auto it : dsCanh) {
            if (cntMST == n - 1) break;
            if (union_set(it.x, it.y)) {
                cntMST++;
                d += it.w;
            }
        }
        cout << d << '\n';
        memset(parent, 0, sizeof(parent));
        memset(sz, 0, sizeof(sz));
        dsCanh.clear();
    }
    return 0;
}