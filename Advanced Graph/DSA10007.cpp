#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001];
vector<pair<int, int>> spanning_tree;
void BFS (int u) {
    visited[u] = 1;
    queue<int> q;
    q.push(u);
    while (q.size()) {
        int tmp = q.front(); q.pop();
        for (int v : ke[tmp]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = 1;
                spanning_tree.push_back({tmp, v});
            }
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e, u; cin >> v >> e >> u;
        for (int i = 0; i < e; i++) {
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        BFS(u);
        if (spanning_tree.size() != v - 1) cout << "-1\n";
        else {
            for (auto it : spanning_tree) cout << it.first << ' ' << it.second << '\n';
        }
        for (int i = 1; i <= v; i++) {
            ke[i].clear();
            visited[i] = 0;
        }
        spanning_tree.clear();
    }
    return 0;
}