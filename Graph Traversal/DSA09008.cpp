#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001];

void DFS (int u) {
    visited[u] = 1;
    for (int x : ke[u]) {
        if (!visited[x]) DFS(x);
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e, x, y; cin >> v >> e;
        while (e--) {
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int tplt = 0;
        for (int i = 1; i <= v; i++) {
            if (!visited[i]) {
                tplt++;
                DFS(i);
            }
        }
        cout << tplt << endl;
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= v; i++) ke[i].clear();
    }
}