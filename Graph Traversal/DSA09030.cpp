#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int color[1001];
bool DFS_two_sided_graph (int u) {
    for (int v : ke[u]) {
        if (color[v] == 0) {
            color[v] = (color[u] == 1) ? 2 : 1;
            if (!DFS_two_sided_graph(v)) return false;
        }
        else if (color[v] == color[u]) return false;
    }
    return true;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        while (e--) {
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int flag = 1;
        for (int i = 1; i <= v; i++) {
            if (!color[i])
                if (!DFS_two_sided_graph(i)) {
                    flag = 0;
                    break;
                }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
        for (int i = 1; i <= v; i++) ke[i].clear();
        memset(color, 0, sizeof(color));
    }
}