#include<bits/stdc++.h>
using namespace std;
vector<int> ke[100001];
int visited[100001];
int res;
int BFS (int u) {
    queue<int> q;
    visited[u] = 1;
    q.push(u);
    int cntFriend = 1;
    while (!q.empty()) {
        int tmp = q.front(); q.pop();
        for (int v : ke[tmp]) {
            if (!visited[v]) {
                cntFriend++;
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    return cntFriend;
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
        res = 1;
        for (int i = 1; i <= v; i++) {
            if (!visited[i]) {
                res = max(res, BFS(i));
            }
        }
        cout << res << '\n';
        for (int i = 1; i <= v; i++) ke[i].clear();
        memset(visited, 0, sizeof(visited));
    }
}