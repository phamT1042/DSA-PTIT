#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001], reverse_ke[1001];
int visited[1001];
void DFS (int u) {
    visited[u] = 1;
    for (int x : ke[u]) {
        if (!visited[x]) DFS(x);
    }
}
void DFS_reverse (int u) {
    visited[u] = 1;
    for (int x : reverse_ke[u]) {
        if (!visited[x]) DFS_reverse(x);
    }
}
string Kosaraju (int v) {
    DFS(1);
    for (int i = 1; i <= v; i++) 
        if (!visited[i]) return "NO";
    memset(visited, 0, sizeof(visited));
    DFS_reverse(1);
    for (int i = 1; i <= v; i++) 
        if (!visited[i]) return "NO";
    return "YES";
}
int main() {
    int T; cin >> T;
    while (T--) {
        int v, e, x, y; cin >> v >> e;
        while (e--) {
            cin >> x >> y;
            ke[x].push_back(y);
            reverse_ke[y].push_back(x);
        }
        cout << Kosaraju(v) << "\n";
        for (int i = 1; i < v; i++) {
            ke[i].clear();
            reverse_ke[i].clear(); 
        }
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}