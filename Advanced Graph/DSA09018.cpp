#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001];
bool Brute_Force (int u, int v) {
    visited[u] = 1;
    int tplt = 0, i;
    if (u == 1) i = 2; 
    else i = 1;
    for (i; i <= v; i++) {
        if (!visited[i]) {
            tplt++;
            queue<int> q;
            q.push(i); 
            visited[i] = 1;
            while (!q.empty()) {
                int tmp = q.front(); q.pop();
                for (int v : ke[tmp]) {
                    if (!visited[v]) {
                        q.push(v);
                        visited[v] = 1;
                    }
                }
            }
        }
    }
    return tplt > 1;
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
        for (int i = 1; i <= v; i++) {
            memset(visited, 0, sizeof(visited));
            if (Brute_Force(i, v)) cout << i << ' ';
        }
        cout << '\n';
        for (int i = 1; i <= v; i++) ke[i].clear();
    }
}