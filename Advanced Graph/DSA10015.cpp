#include<bits/stdc++.h>
using namespace std;
int parent[101], sz[101];
int v, e;
struct edge {
    int x, y, w;
    edge (int a, int b, int c) {
        x = a; y = b; w = c;
    }
};
vector<edge> dsCanh;
void make_set() {
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int find_set(int s) {
    if (s == parent[s]) return s;
    return parent[s] = find_set(parent[s]);
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
void input() {
    cin >> v >> e;
    int x, y, z;
    for (int i = 0; i < e; i++) {
        cin >> x >> y >> z;
        dsCanh.push_back(edge(x, y, z));
        dsCanh.push_back(edge(y, x, z));
    }
}
int Kruskal() {
    int cntMST = 0, d = 0;
    sort(dsCanh.begin(), dsCanh.end(), [](edge a, edge b) {return a.w < b.w;});
    for (auto it : dsCanh) {
        if (cntMST == v - 1) return d;
        if (union_set(it.x, it.y)) {
            cntMST++;
            d += it.w;
        }
    }
    return 0;
}
int main() {
    int t; cin >> t;
    while (t--) {
        input();
        make_set();
        cout << Kruskal() << '\n';
        memset(parent, 0, sizeof(parent));
        memset(sz, 0, sizeof(sz));
        dsCanh.clear();
    }
}