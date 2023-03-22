#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001];
vector<pair<int, int>> dsCanh;
void DFS (int u) {
    visited[u] = 1;
    for (int x : ke[u]) {
        if (!visited[x]) DFS(x);
    }
}
void DFS_ignore (int u, int s, int t) {
    visited[u] = 1;
    for (int x : ke[u]) {
        if (u == s && x == t || x == s && u == t) continue;
        if (!visited[x]) DFS_ignore(x, s, t);
    }
}
void Brute_Force(int v) {
    int tplt = 0;
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            tplt++;
            DFS(i);
        }
    }
    for (auto it : dsCanh) {
        memset(visited, 0, sizeof(visited));
        int changeTPLT = 0;
        for (int i = 1; i <= v; i++) {
            if (!visited[i]) {
                changeTPLT++;
                DFS_ignore(i, it.first, it.second);
            }
        }
        if (changeTPLT > tplt) cout << it.first << ' ' << it.second << ' ';
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        while (e--) {
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
            dsCanh.push_back({x, y});
        }
        Brute_Force(v);
        memset(visited, 0, sizeof(visited));
        dsCanh.clear();
        for (int i = 1; i <= v; i++) ke[i].clear();
        cout << "\n";
    }
}