#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001], parent[1001];
int flag, t;
void DFS (int s) {
    for (int x : ke[s]) {
        if (!visited[x]) {
            parent[x] = s;
            visited[x] = 1;
            if (x == t) {
                flag = 1;
                return;
            }
            DFS(x);
        }
    }
}
int main() {
    int T; cin >> T;
    while (T--) {
        flag = 0;
        int v, e, s, x, y; cin >> v >> e >> s >> t;
        while (e--) {
            cin >> x >> y;
            ke[x].push_back(y);
        }
        parent[s] = 0;
        visited[s] = 1;
        DFS(s);
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