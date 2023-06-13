#include<bits/stdc++.h>
using namespace std;
int visited[1001];
vector<int> ke[1001];
unordered_map<int, int> posCanGo;
//Tạo danh sách các vị trí có thể đến của người đầu tiên
void DFS_first (int u) {
    visited[u] = 1;
    posCanGo[u] = 1;
    for (int v : ke[u]) {
        if (!visited[v]) DFS_first(v);
    }
}
//Tạo danh sách con các vị trí có thể đến từ người 2 trở đi
void DFS (int u, int i) {
    visited[u] = 1;
    if (posCanGo[u] == i - 1) posCanGo[u] = i;
    for (int v : ke[u]) {
        if (!visited[v]) DFS(v, i);
    }
}
int main () {
    int k, n, m; cin >> k >> n >> m;
    int pos[k + 1];
    for (int i = 1; i <= k; i++) cin >> pos[i];
    while (m--) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
    DFS_first(pos[1]);
    for (int i = 2; i <= k; i++) {
        memset(visited, 0, sizeof(visited));
        DFS(pos[i], i);
    }
    int res = 0;
    for (auto it : posCanGo) 
        if (it.second == k) res++;
    cout << res;
    return 0;
}