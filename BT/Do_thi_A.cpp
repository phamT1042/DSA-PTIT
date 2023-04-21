#include<bits/stdc++.h>
using namespace std;
vector<int> ke[20001];
int n, m, s;
int vs[20001];
void DFS (int u) {
    vs[u] = 1;
    for (int v : ke[u]) 
        if (!vs[v]) DFS(v);
}
int main() {
        cin >> n >> m;
        while (m--) {
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        vs[i] = 1;
        for (int j = 1; j <= n; j++) {
            if (!vs[j]) {
                cnt++;
                DFS(j);
            }
        }
        cout << cnt << '\n';
        memset(vs, 0, sizeof(vs));
    }
    return 0;
}