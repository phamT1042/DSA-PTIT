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
void Brute_Force(int v) {
    int tplt = 0;
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            tplt++;
            DFS(i);
        }
    }
    for (int i = 1; i <= v; i++) {
        memset(visited, 0, sizeof(visited));
        int changeTPLT = 0;
        visited[i] = 1;
        for (int j = 1; j <= v; j++) {
            if (!visited[j]) {
                changeTPLT++;
                DFS(j);
            }
        }
        if (changeTPLT > tplt) cout << i << ' ';
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
        }
        Brute_Force(v);
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= v; i++) ke[i].clear();
        cout << "\n";
    }
}