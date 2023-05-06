#include<bits/stdc++.h>
using namespace std;
int parent[100], sz[100], n;
struct edge {
    int u, v;
    double w;
    edge (int x, int y, double z) {
        u = x; v = y; w = z;
    }
};
vector<edge> dsCanh;
void Make() {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
} 
int Find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}
bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}
double khoangCach(pair<double, double> u, pair<double, double> v) {
    return sqrt((u.first - v.first) * (u.first - v.first) + (u.second - v.second) * (u.second - v.second));
}
double Kruskal() {
    int cntMST = 0;
    double d = 0;
    sort(dsCanh.begin(), dsCanh.end(), [] (edge a, edge b) {return a.w < b.w;});
    for (int i = 0; i < dsCanh.size(); i++) {
        edge e = dsCanh[i];
        if (Union(e.u, e.v)) {
            cntMST++;
            d += e.w;
        }
        if (cntMST == n - 1) return d;
    }
    return 0;
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        Make();
        vector<pair<double, double>> dsDinh;
        double x, y;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            dsDinh.push_back({x, y});
        }
        dsCanh.clear();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                dsCanh.push_back(edge(i, j, khoangCach(dsDinh[i], dsDinh[j])));
            }
        }
        cout << fixed << setprecision(6) << Kruskal() << '\n';
    }
    return 0;
}