#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001];
int DFS_check_cycle (int u, int parent_u) {
    visited[u] = 1;
    for (int v : ke[u]) {
        if (!visited[v]) {
            if (DFS_check_cycle(v, u)) return true;
        }
        else if (v != parent_u) return true;
    }
    return false;
}
string check (int v) {
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            if (DFS_check_cycle(i, 0)) return "YES";
        }
    }
    return "NO";
}
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        for (int i = 1; i <= v; i++) ke[i].clear();
        memset(visited, 0, sizeof(visited));
        while (e--) {
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        cout << check(v) << endl;
    }
}