#include<bits/stdc++.h>
using namespace std;
struct edge {
    int x, y, w;
    edge (int a, int b, int c) {
        this->x = a;
        this->y = b;
        this->w = c;
    }
};
int Bellman_Ford (vector<edge> dsCanh, int v, int s) {
    vector<int> d(v + 1, INT_MAX);
    d[s] = 0;
    for (int i = 1; i < v; i++) {
        for (auto it : dsCanh) {
            if (d[it.x] != INT_MAX)
                d[it.y] = min(d[it.y], d[it.x] + it.w);
        }
    }
    for (auto it : dsCanh) {
        if (d[it.x] != INT_MAX)
            if (d[it.y] > d[it.x] + it.w) return 1;
    }
    return 0; 
}
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        vector<edge> dsCanh;
        while (e--) {
            int x, y, w; cin >> x >> y >> w;
            edge tmp1 (x, y, w);
            dsCanh.push_back(tmp1);
        }
        int flag = 0;
        for (int i = 1; i <= v; i++) {
            if (Bellman_Ford(dsCanh, v, i)) {
                flag = 1; 
                break;
            }
        }
        cout << flag << '\n';
    }
}