#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001];
int BFS (int u, int v) {
    queue<pair<int, int>> q;
    q.push({0, u});
    visited[u] = 1;
    while(q.size()) {
        auto it = q.front(); q.pop();
        for (int i : ke[it.second]) {
            if (!visited[i]) {
                if (i == v) return it.first + 1;
                visited[i] = 1;
                q.push({it.first + 1, i});
            }
        }
    }
    return 0;
}
int main () {
    int t; cin >> t;
    while (t--) {
        int n, x, y; cin >> n;
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int q; cin >> q;
        while (q--) {
            cin >> x >> y;
            if (x == y) cout << 0 << '\n';
            else {
                cout << BFS(x, y) << '\n';
                for (int i = 1; i <= n; i++) visited[i] = 0;
            }
        }
        for (int i = 1; i <= n; i++) ke[i].clear();
    }
    return 0;
}