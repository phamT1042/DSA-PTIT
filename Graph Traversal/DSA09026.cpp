#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001], parent[1001];
int flag;
void BFS (int s, int t) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = 0;
    while (!q.empty()) {
        int tmp = q.front(); q.pop();
        for (int x : ke[tmp]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = 1;
                parent[x] = tmp;
                if (x == t) {
                    flag = 1;
                    return;
                }
            }
        }
    }
}
int main() {
    int T; cin >> T;
    while (T--) {
        flag = 0;
        int v, e, s, t, x, y; cin >> v >> e >> s >> t;
        while (e--) {
            cin >> x >> y;
            ke[x].push_back(y);
        }
        BFS(s, t);
        if (flag) {
            vector<int> go;
            while (t != 0) {
                go.push_back(t);
                t = parent[t];
            }
            reverse(go.begin(), go.end());
            for (int x : go) cout << x << ' ';
        }
        else cout << -1;
        cout << "\n";
        for (int i = 1; i < 1001; i++) ke[i].clear();
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}