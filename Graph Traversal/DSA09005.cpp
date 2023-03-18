#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001];
void BFS (int u) {
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while (!q.empty()) {
        int tmp = q.front(); q.pop();
        cout << tmp << ' ';
        for (int x : ke[tmp]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = 1;
            }
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e, u, x, y; cin >> v >> e >> u;
        while (e--) {
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        BFS(u);
        cout << endl;
        for (int i = 1; i < 1001; i++) ke[i].clear();
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}