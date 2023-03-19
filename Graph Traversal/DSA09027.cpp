#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001];
string BFS (int s, int t) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
        int tmp = q.front(); q.pop();
        for (int x : ke[tmp]) {
            if (!visited[x]) {
                if (x == t) return "YES\n";
                q.push(x);
                visited[x] = 1;
            }
        }
    }
    return "NO\n";
}
int main() {
    int T; cin >> T;
    while (T--) {
        int n, m, x, y; cin >> n >> m;
        while (m--) {
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int q; cin >> q;
        while (q--) {
            int s, t; cin >> s >> t;
            cout << BFS(s, t);
            memset(visited, 0, sizeof(visited));
        }
        for (int i = 1; i < 1001; i++) ke[i].clear();
    }
    return 0;
}