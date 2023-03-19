#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001];
int flag;
void BFS (int s, int t) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
        int tmp = q.front(); q.pop();
        for (int x : ke[tmp]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = 1;
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
        int n, m, x, y; cin >> n >> m;
        while (m--) {
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int q; cin >> q;
        while (q--) {
            flag = 0;
            int s, t; cin >> s >> t;
            BFS(s, t);
            if (flag) cout << "YES\n";
            else cout << "NO\n";
            memset(visited, 0, sizeof(visited));
        }
        for (int i = 1; i < 1001; i++) ke[i].clear();
    }
    return 0;
}