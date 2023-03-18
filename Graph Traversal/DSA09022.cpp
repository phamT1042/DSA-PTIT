#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001];
void DFS (int u) {
    visited[u] = 1;
    cout << u << ' ';
    for (int x : ke[u]) {
        if (!visited[x]) DFS(x);
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e, u, x, y; cin >> v >> e >> u;
        while (e--) {
            cin >> x >> y;
            ke[x].push_back(y);
        }
        DFS(u);
        cout << endl;
        for (int i = 1; i < 1001; i++) ke[i].clear();
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}